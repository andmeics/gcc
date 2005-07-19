/* Functions to support general ended bitmaps.
   Copyright (C) 1997, 1998, 1999, 2000, 2001, 2003, 2004, 2005
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301, USA.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "flags.h"
#include "obstack.h"
#include "ggc.h"
#include "bitmap.h"

/* Global data */
bitmap_element bitmap_zero_bits;  /* An element of all zero bits.  */
bitmap_obstack bitmap_default_obstack;    /* The default bitmap obstack.  */
static GTY((deletable)) bitmap_element *bitmap_ggc_free; /* Freelist of
							    GC'd elements.  */

static void bitmap_elem_to_freelist (bitmap, bitmap_element *);
static void bitmap_element_free (bitmap, bitmap_element *);
static bitmap_element *bitmap_element_allocate (bitmap);
static int bitmap_element_zerop (bitmap_element *);
static void bitmap_element_link (bitmap, bitmap_element *);
static bitmap_element *bitmap_elt_insert_after (bitmap, bitmap_element *);
static void bitmap_elt_clear_from (bitmap, bitmap_element *);
static bitmap_element *bitmap_find_bit (bitmap, unsigned int);


/* Add ELEM to the appropriate freelist.  */
static inline void
bitmap_elem_to_freelist (bitmap head, bitmap_element *elt)
{
  bitmap_obstack *bit_obstack = head->obstack;
  
  elt->next = NULL;
  if (bit_obstack)
    {
      elt->prev = bit_obstack->elements;
      bit_obstack->elements = elt;
    }
  else
    {
      elt->prev = bitmap_ggc_free;
      bitmap_ggc_free = elt;
    }
}

/* Free a bitmap element.  Since these are allocated off the
   bitmap_obstack, "free" actually means "put onto the freelist".  */

static inline void
bitmap_element_free (bitmap head, bitmap_element *elt)
{
  bitmap_element *next = elt->next;
  bitmap_element *prev = elt->prev;

  if (prev)
    prev->next = next;

  if (next)
    next->prev = prev;

  if (head->first == elt)
    head->first = next;

  /* Since the first thing we try is to insert before current,
     make current the next entry in preference to the previous.  */
  if (head->current == elt)
    {
      head->current = next != 0 ? next : prev;
      if (head->current)
	head->indx = head->current->indx;
    }
  bitmap_elem_to_freelist (head, elt);
}

/* Allocate a bitmap element.  The bits are cleared, but nothing else is.  */

static inline bitmap_element *
bitmap_element_allocate (bitmap head)
{
  bitmap_element *element;
  bitmap_obstack *bit_obstack = head->obstack;
      
  if (bit_obstack)
    {
      element = bit_obstack->elements;
      
      if (element)
	/* Use up the inner list first before looking at the next
	   element of the outer list.  */
	if (element->next)
	  {
	    bit_obstack->elements = element->next;
	    bit_obstack->elements->prev = element->prev;
	  }
	else
	  /*  Inner list was just a singleton.  */
	  bit_obstack->elements = element->prev;
      else
	element = XOBNEW (&bit_obstack->obstack, bitmap_element);
    }
  else
    {
      element = bitmap_ggc_free;
      if (element)
	/* Use up the inner list first before looking at the next
	   element of the outer list.  */
	if (element->next)
	  {
	    bitmap_ggc_free = element->next;
	    bitmap_ggc_free->prev = element->prev;
	  }
	else
	  /*  Inner list was just a singleton.  */
	  bitmap_ggc_free = element->prev;
      else
	element = GGC_NEW (bitmap_element);
    }

  memset (element->bits, 0, sizeof (element->bits));

  return element;
}

/* Remove ELT and all following elements from bitmap HEAD.  */

void
bitmap_elt_clear_from (bitmap head, bitmap_element *elt)
{
  bitmap_element *prev;
  bitmap_obstack *bit_obstack = head->obstack;

  if (!elt) return;

  prev = elt->prev;
  if (prev)
    {
      prev->next = NULL;
      if (head->current->indx > prev->indx)
	{
	  head->current = prev;
	  head->indx = prev->indx;
	}
    } 
  else
    {
      head->first = NULL;
      head->current = NULL;
      head->indx = 0;
    }

  /* Put the entire list onto the free list in one operation. */ 
  if (bit_obstack)
    {
      elt->prev = bit_obstack->elements; 
      bit_obstack->elements = elt;
    }
  else
    {
      elt->prev = bitmap_ggc_free;
      bitmap_ggc_free = elt;
    }
}

/* Clear a bitmap by freeing the linked list.  */

inline void
bitmap_clear (bitmap head)
{
  if (head->first)
    bitmap_elt_clear_from (head, head->first);
}

/* Initialize a bitmap obstack.  If BIT_OBSTACK is NULL, initialize
   the default bitmap obstack.  */

void
bitmap_obstack_initialize (bitmap_obstack *bit_obstack)
{
  if (!bit_obstack)
    bit_obstack = &bitmap_default_obstack;

#if !defined(__GNUC__) || (__GNUC__ < 2)
#define __alignof__(type) 0
#endif

  bit_obstack->elements = NULL;
  bit_obstack->heads = NULL;
  obstack_specify_allocation (&bit_obstack->obstack, OBSTACK_CHUNK_SIZE,
			      __alignof__ (bitmap_element),
			      obstack_chunk_alloc,
			      obstack_chunk_free);
}

/* Release the memory from a bitmap obstack.  If BIT_OBSTACK is NULL,
   release the default bitmap obstack.  */

void
bitmap_obstack_release (bitmap_obstack *bit_obstack)
{
  if (!bit_obstack)
    bit_obstack = &bitmap_default_obstack;
  
  bit_obstack->elements = NULL;
  bit_obstack->heads = NULL;
  obstack_free (&bit_obstack->obstack, NULL);
}

/* Create a new bitmap on an obstack.  If BIT_OBSTACK is NULL, create
   it on the default bitmap obstack.  */

bitmap
bitmap_obstack_alloc (bitmap_obstack *bit_obstack)
{
  bitmap map;

  if (!bit_obstack)
    bit_obstack = &bitmap_default_obstack;
  map = bit_obstack->heads;
  if (map)
    bit_obstack->heads = (void *)map->first;
  else
    map = XOBNEW (&bit_obstack->obstack, bitmap_head);
  bitmap_initialize (map, bit_obstack);

  return map;
}

/* Create a new GCd bitmap.  */

bitmap
bitmap_gc_alloc (void)
{
  bitmap map;

  map = GGC_NEW (struct bitmap_head_def);
  bitmap_initialize (map, NULL);

  return map;
}

/* Release an obstack allocated bitmap.  */

void
bitmap_obstack_free (bitmap map)
{
  if (map)
    {
      bitmap_clear (map);
      map->first = (void *)map->obstack->heads;
      map->obstack->heads = map;
    }
}


/* Return nonzero if all bits in an element are zero.  */

static inline int
bitmap_element_zerop (bitmap_element *element)
{
#if BITMAP_ELEMENT_WORDS == 2
  return (element->bits[0] | element->bits[1]) == 0;
#else
  unsigned i;

  for (i = 0; i < BITMAP_ELEMENT_WORDS; i++)
    if (element->bits[i] != 0)
      return 0;

  return 1;
#endif
}

/* Link the bitmap element into the current bitmap linked list.  */

static inline void
bitmap_element_link (bitmap head, bitmap_element *element)
{
  unsigned int indx = element->indx;
  bitmap_element *ptr;

  /* If this is the first and only element, set it in.  */
  if (head->first == 0)
    {
      element->next = element->prev = 0;
      head->first = element;
    }

  /* If this index is less than that of the current element, it goes someplace
     before the current element.  */
  else if (indx < head->indx)
    {
      for (ptr = head->current;
	   ptr->prev != 0 && ptr->prev->indx > indx;
	   ptr = ptr->prev)
	;

      if (ptr->prev)
	ptr->prev->next = element;
      else
	head->first = element;

      element->prev = ptr->prev;
      element->next = ptr;
      ptr->prev = element;
    }

  /* Otherwise, it must go someplace after the current element.  */
  else
    {
      for (ptr = head->current;
	   ptr->next != 0 && ptr->next->indx < indx;
	   ptr = ptr->next)
	;

      if (ptr->next)
	ptr->next->prev = element;

      element->next = ptr->next;
      element->prev = ptr;
      ptr->next = element;
    }

  /* Set up so this is the first element searched.  */
  head->current = element;
  head->indx = indx;
}

/* Insert a new uninitialized element into bitmap HEAD after element
   ELT.  If ELT is NULL, insert the element at the start.  Return the
   new element.  */

static bitmap_element *
bitmap_elt_insert_after (bitmap head, bitmap_element *elt)
{
  bitmap_element *node = bitmap_element_allocate (head);

  if (!elt)
    {
      if (!head->current)
	head->current = node;
      node->next = head->first;
      if (node->next)
	node->next->prev = node;
      head->first = node;
      node->prev = NULL;
    }
  else
    {
      gcc_assert (head->current);
      node->next = elt->next;
      if (node->next)
	node->next->prev = node;
      elt->next = node;
      node->prev = elt;
    }
  return node;
}

/* Copy a bitmap to another bitmap.  */

void
bitmap_copy (bitmap to, bitmap from)
{
  bitmap_element *from_ptr, *to_ptr = 0;

  bitmap_clear (to);

  /* Copy elements in forward direction one at a time.  */
  for (from_ptr = from->first; from_ptr; from_ptr = from_ptr->next)
    {
      bitmap_element *to_elt = bitmap_element_allocate (to);

      to_elt->indx = from_ptr->indx;
      memcpy (to_elt->bits, from_ptr->bits, sizeof (to_elt->bits));

      /* Here we have a special case of bitmap_element_link, for the case
	 where we know the links are being entered in sequence.  */
      if (to_ptr == 0)
	{
	  to->first = to->current = to_elt;
	  to->indx = from_ptr->indx;
	  to_elt->next = to_elt->prev = 0;
	}
      else
	{
	  to_elt->prev = to_ptr;
	  to_elt->next = 0;
	  to_ptr->next = to_elt;
	}

      to_ptr = to_elt;
    }
}

/* Find a bitmap element that would hold a bitmap's bit.
   Update the `current' field even if we can't find an element that
   would hold the bitmap's bit to make eventual allocation
   faster.  */

static inline bitmap_element *
bitmap_find_bit (bitmap head, unsigned int bit)
{
  bitmap_element *element;
  unsigned int indx = bit / BITMAP_ELEMENT_ALL_BITS;

  if (head->current == 0
      || head->indx == indx)
    return head->current;

  if (head->indx < indx)
    /* INDX is beyond head->indx.  Search from head->current
       forward.  */
    for (element = head->current;
	 element->next != 0 && element->indx < indx;
	 element = element->next)
      ;

  else if (head->indx / 2 < indx)
    /* INDX is less than head->indx and closer to head->indx than to
       0.  Search from head->current backward.  */
    for (element = head->current;
	 element->prev != 0 && element->indx > indx;
	 element = element->prev)
      ;

  else
    /* INDX is less than head->indx and closer to 0 than to
       head->indx.  Search from head->first forward.  */
    for (element = head->first;
	 element->next != 0 && element->indx < indx;
	 element = element->next)
      ;

  /* `element' is the nearest to the one we want.  If it's not the one we
     want, the one we want doesn't exist.  */
  head->current = element;
  head->indx = element->indx;
  if (element != 0 && element->indx != indx)
    element = 0;

  return element;
}

/* Clear a single bit in a bitmap.  */

void
bitmap_clear_bit (bitmap head, int bit)
{
  bitmap_element *ptr = bitmap_find_bit (head, bit);

  if (ptr != 0)
    {
      unsigned bit_num  = bit % BITMAP_WORD_BITS;
      unsigned word_num = bit / BITMAP_WORD_BITS % BITMAP_ELEMENT_WORDS;
      ptr->bits[word_num] &= ~ (((BITMAP_WORD) 1) << bit_num);

      /* If we cleared the entire word, free up the element.  */
      if (bitmap_element_zerop (ptr))
	bitmap_element_free (head, ptr);
    }
}

/* Set a single bit in a bitmap.  */

void
bitmap_set_bit (bitmap head, int bit)
{
  bitmap_element *ptr = bitmap_find_bit (head, bit);
  unsigned word_num = bit / BITMAP_WORD_BITS % BITMAP_ELEMENT_WORDS;
  unsigned bit_num  = bit % BITMAP_WORD_BITS;
  BITMAP_WORD bit_val = ((BITMAP_WORD) 1) << bit_num;

  if (ptr == 0)
    {
      ptr = bitmap_element_allocate (head);
      ptr->indx = bit / BITMAP_ELEMENT_ALL_BITS;
      ptr->bits[word_num] = bit_val;
      bitmap_element_link (head, ptr);
    }
  else
    ptr->bits[word_num] |= bit_val;
}

/* Return whether a bit is set within a bitmap.  */

int
bitmap_bit_p (bitmap head, int bit)
{
  bitmap_element *ptr;
  unsigned bit_num;
  unsigned word_num;

  ptr = bitmap_find_bit (head, bit);
  if (ptr == 0)
    return 0;

  bit_num = bit % BITMAP_WORD_BITS;
  word_num = bit / BITMAP_WORD_BITS % BITMAP_ELEMENT_WORDS;

  return (ptr->bits[word_num] >> bit_num) & 1;
}

/* Return the bit number of the first set bit in the bitmap.  The
   bitmap must be non-empty.  */

unsigned
bitmap_first_set_bit (bitmap a)
{
  bitmap_element *elt = a->first;
  unsigned bit_no;
  BITMAP_WORD word;
  unsigned ix;
  
  gcc_assert (elt);
  bit_no = elt->indx * BITMAP_ELEMENT_ALL_BITS;
  for (ix = 0; ix != BITMAP_ELEMENT_WORDS; ix++)
    {
      word = elt->bits[ix];
      if (word)
	goto found_bit;
    }
  gcc_unreachable ();
 found_bit:
  bit_no += ix * BITMAP_WORD_BITS;

#if GCC_VERSION >= 3004
  gcc_assert (sizeof(long) == sizeof (word));
  bit_no += __builtin_ctzl (word);
#else
  /* Binary search for the first set bit.  */
#if BITMAP_WORD_BITS > 64
#error "Fill out the table."
#endif
#if BITMAP_WORD_BITS > 32
  if (!(word & 0xffffffff))
    word >>= 32, bit_no += 32;
#endif
  if (!(word & 0xffff))
    word >>= 16, bit_no += 16;
  if (!(word & 0xff))
    word >>= 8, bit_no += 8;
  if (!(word & 0xf))
    word >>= 4, bit_no += 4;
  if (!(word & 0x3))
    word >>= 2, bit_no += 2;
  if (!(word & 0x1))
    word >>= 1, bit_no += 1;
  
 gcc_assert (word & 1);
#endif
 return bit_no;
}


/* DST = A & B.  */

void
bitmap_and (bitmap dst, bitmap a, bitmap b)
{
  bitmap_element *dst_elt = dst->first;
  bitmap_element *a_elt = a->first;
  bitmap_element *b_elt = b->first;
  bitmap_element *dst_prev = NULL;

  gcc_assert (dst != a && dst != b);

  if (a == b)
    {
      bitmap_copy (dst, a);
      return;
    }

  while (a_elt && b_elt)
    {
      if (a_elt->indx < b_elt->indx)
	a_elt = a_elt->next;
      else if (b_elt->indx < a_elt->indx)
	b_elt = b_elt->next;
      else
	{
	  /* Matching elts, generate A & B.  */
	  unsigned ix;
	  BITMAP_WORD ior = 0;

	  if (!dst_elt)
	    dst_elt = bitmap_elt_insert_after (dst, dst_prev);
	  
	  dst_elt->indx = a_elt->indx;
	  for (ix = BITMAP_ELEMENT_WORDS; ix--;)
	    {
	      BITMAP_WORD r = a_elt->bits[ix] & b_elt->bits[ix];

	      dst_elt->bits[ix] = r;
	      ior |= r;
	    }
	  if (ior)
	    {
	      dst_prev = dst_elt;
	      dst_elt = dst_elt->next;
	    }
	  a_elt = a_elt->next;
	  b_elt = b_elt->next;
	}
    }
  bitmap_elt_clear_from (dst, dst_elt);
  gcc_assert (!dst->current == !dst->first);
  if (dst->current)
    dst->indx = dst->current->indx;
}

/* A &= B.  */

void
bitmap_and_into (bitmap a, bitmap b)
{
  bitmap_element *a_elt = a->first;
  bitmap_element *b_elt = b->first;
  bitmap_element *next;

  if (a == b) 
    return;

  while (a_elt && b_elt)
    {
      if (a_elt->indx < b_elt->indx)
	{
	  next = a_elt->next;
	  bitmap_element_free (a, a_elt);
	  a_elt = next;
	}
      else if (b_elt->indx < a_elt->indx)
	b_elt = b_elt->next;
      else
	{
	  /* Matching elts, generate A &= B.  */
	  unsigned ix;
	  BITMAP_WORD ior = 0;

	  for (ix = BITMAP_ELEMENT_WORDS; ix--;)
	    {
	      BITMAP_WORD r = a_elt->bits[ix] & b_elt->bits[ix];

	      a_elt->bits[ix] = r;
	      ior |= r;
	    }
	  next = a_elt->next;
	  if (!ior)
	    bitmap_element_free (a, a_elt);
	  a_elt = next;
	  b_elt = b_elt->next;
	}
    }
  bitmap_elt_clear_from (a, a_elt);
  gcc_assert (!a->current == !a->first);
  gcc_assert (!a->current || a->indx == a->current->indx);
}

/* DST = A & ~B  */

void
bitmap_and_compl (bitmap dst, bitmap a, bitmap b)
{
  bitmap_element *dst_elt = dst->first;
  bitmap_element *a_elt = a->first;
  bitmap_element *b_elt = b->first;
  bitmap_element *dst_prev = NULL;

  gcc_assert (dst != a && dst != b);
  
  if (a == b)
    {
      bitmap_clear (dst);
      return;
    }

  while (a_elt)
    {
      if (!b_elt || a_elt->indx < b_elt->indx)
	{
	  /* Copy a_elt.  */
	  if (!dst_elt)
	    dst_elt = bitmap_elt_insert_after (dst, dst_prev);
	  
	  dst_elt->indx = a_elt->indx;
	  memcpy (dst_elt->bits, a_elt->bits, sizeof (dst_elt->bits));
	  dst_prev = dst_elt;
	  dst_elt = dst_elt->next;
	  a_elt = a_elt->next;
	}
      else if (b_elt->indx < a_elt->indx)
	b_elt = b_elt->next;
      else
	{
	  /* Matching elts, generate A & ~B.  */
	  unsigned ix;
	  BITMAP_WORD ior = 0;

	  if (!dst_elt)
	    dst_elt = bitmap_elt_insert_after (dst, dst_prev);
	  
	  dst_elt->indx = a_elt->indx;
	  for (ix = BITMAP_ELEMENT_WORDS; ix--;)
	    {
	      BITMAP_WORD r = a_elt->bits[ix] & ~b_elt->bits[ix];

	      dst_elt->bits[ix] = r;
	      ior |= r;
	    }
	  if (ior)
	    {
	      dst_prev = dst_elt;
	      dst_elt = dst_elt->next;
	    }
	  a_elt = a_elt->next;
	  b_elt = b_elt->next;
	}
    }
  bitmap_elt_clear_from (dst, dst_elt);
  gcc_assert (!dst->current == !dst->first);
  if (dst->current)
    dst->indx = dst->current->indx;
}

/* A &= ~B. Returns true if A changes */

bool
bitmap_and_compl_into (bitmap a, bitmap b)
{
  bitmap_element *a_elt = a->first;
  bitmap_element *b_elt = b->first;
  bitmap_element *next;
  BITMAP_WORD changed = 0;

  if (a == b)
    {
      if (bitmap_empty_p (a))
	return false;
      else
	{
	  bitmap_clear (a);
	  return true;
	}
    }

  while (a_elt && b_elt)
    {
      if (a_elt->indx < b_elt->indx)
	a_elt = a_elt->next;
      else if (b_elt->indx < a_elt->indx)
	b_elt = b_elt->next;
      else
	{
	  /* Matching elts, generate A &= ~B.  */
	  unsigned ix;
	  BITMAP_WORD ior = 0;

	  for (ix = BITMAP_ELEMENT_WORDS; ix--;)
	    {
	      BITMAP_WORD cleared = a_elt->bits[ix] & b_elt->bits[ix];
	      BITMAP_WORD r = a_elt->bits[ix] ^ cleared;

	      a_elt->bits[ix] = r;
	      changed |= cleared;
	      ior |= r;
	    }
	  next = a_elt->next;
	  if (!ior)
	    bitmap_element_free (a, a_elt);
	  a_elt = next;
	  b_elt = b_elt->next;
	}
    }
  gcc_assert (!a->current == !a->first);
  gcc_assert (!a->current || a->indx == a->current->indx);
  return changed != 0;
}

/* DST = A | B.  Return true if DST changes.  */

bool
bitmap_ior (bitmap dst, bitmap a, bitmap b)
{
  bitmap_element *dst_elt = dst->first;
  bitmap_element *a_elt = a->first;
  bitmap_element *b_elt = b->first;
  bitmap_element *dst_prev = NULL;
  bool changed = false;  

  gcc_assert (dst != a && dst != b);

  while (a_elt || b_elt)
    {
      if (a_elt && b_elt && a_elt->indx == b_elt->indx)
	{
	  /* Matching elts, generate A | B.  */
	  unsigned ix;
	      
	  if (!changed && dst_elt && dst_elt->indx == a_elt->indx)
	    {
	      for (ix = BITMAP_ELEMENT_WORDS; ix--;)
		{
		  BITMAP_WORD r = a_elt->bits[ix] | b_elt->bits[ix];

		  if (r != dst_elt->bits[ix])
		    {
		      dst_elt->bits[ix] = r;
		      changed = true;
		    }
		}
	    }
	  else
	    {
	      changed = true;
	      if (!dst_elt)
		dst_elt = bitmap_elt_insert_after (dst, dst_prev);
	      dst_elt->indx = a_elt->indx;
	      for (ix = BITMAP_ELEMENT_WORDS; ix--;)
		{
		  BITMAP_WORD r = a_elt->bits[ix] | b_elt->bits[ix];
		  
		  dst_elt->bits[ix] = r;
		}
	    }
	  a_elt = a_elt->next;
	  b_elt = b_elt->next;
	  dst_prev = dst_elt;
	  dst_elt = dst_elt->next;
	}
      else
	{
	  /* Copy a single element.  */
	  bitmap_element *src;

	  if (!b_elt || (a_elt && a_elt->indx < b_elt->indx))
	    {
	      src = a_elt;
	      a_elt = a_elt->next;
	    }
	  else
	    {
	      src = b_elt;
	      b_elt = b_elt->next;
	    }

	  if (!changed && dst_elt && dst_elt->indx == src->indx)
	    {
	      unsigned ix;
	      
	      for (ix = BITMAP_ELEMENT_WORDS; ix--;)
		if (src->bits[ix] != dst_elt->bits[ix])
		  {
		    dst_elt->bits[ix] = src->bits[ix];
		    changed = true;
		  }
	    }
	  else
	    {
	      changed = true;
	      if (!dst_elt)
		dst_elt = bitmap_elt_insert_after (dst, dst_prev);
	      dst_elt->indx = src->indx;
	      memcpy (dst_elt->bits, src->bits, sizeof (dst_elt->bits));
	    }
	  
	  dst_prev = dst_elt;
	  dst_elt = dst_elt->next;
	}
    }

  if (dst_elt)
    {
      changed = true;
      bitmap_elt_clear_from (dst, dst_elt);
    }
  gcc_assert (!dst->current == !dst->first);
  if (dst->current)
    dst->indx = dst->current->indx;
  return changed;
}

/* A |= B.  Return true if A changes.  */

bool
bitmap_ior_into (bitmap a, bitmap b)
{
  bitmap_element *a_elt = a->first;
  bitmap_element *b_elt = b->first;
  bitmap_element *a_prev = NULL;
  bool changed = false;

  if (a == b)
    return false;

  while (b_elt)
    {
      if (!a_elt || b_elt->indx < a_elt->indx)
	{
	  /* Copy b_elt.  */
	  bitmap_element *dst = bitmap_elt_insert_after (a, a_prev);
	  
	  dst->indx = b_elt->indx;
	  memcpy (dst->bits, b_elt->bits, sizeof (dst->bits));
	  a_prev = dst;
	  b_elt = b_elt->next;
	  changed = true;
	}
      else if (a_elt->indx < b_elt->indx)
	{
	  a_prev = a_elt;
	  a_elt = a_elt->next;
	}
      else
	{
	  /* Matching elts, generate A |= B.  */
	  unsigned ix;

	  if (changed)
	    for (ix = BITMAP_ELEMENT_WORDS; ix--;)
	      {
		BITMAP_WORD r = a_elt->bits[ix] | b_elt->bits[ix];
		
		a_elt->bits[ix] = r;
	      }
	  else
	    for (ix = BITMAP_ELEMENT_WORDS; ix--;)
	      {
		BITMAP_WORD r = a_elt->bits[ix] | b_elt->bits[ix];

		if (a_elt->bits[ix] != r)
		  {
		    changed = true;
		    a_elt->bits[ix] = r;
		  }
	      }
	  b_elt = b_elt->next;
	  a_prev = a_elt;
	  a_elt = a_elt->next;
	}
    }
  gcc_assert (!a->current == !a->first);
  if (a->current)
    a->indx = a->current->indx;
  return changed;
}

/* DST = A ^ B  */

void
bitmap_xor (bitmap dst, bitmap a, bitmap b)
{
  bitmap_element *dst_elt = dst->first;
  bitmap_element *a_elt = a->first;
  bitmap_element *b_elt = b->first;
  bitmap_element *dst_prev = NULL;

  gcc_assert (dst != a && dst != b);
  if (a == b)
    {
      bitmap_clear (dst);
      return;
    }

  while (a_elt || b_elt)
    {
      if (a_elt && b_elt && a_elt->indx == b_elt->indx)
	{
	  /* Matching elts, generate A ^ B.  */
	  unsigned ix;
	  BITMAP_WORD ior = 0;

	  if (!dst_elt)
	    dst_elt = bitmap_elt_insert_after (dst, dst_prev);
	  
	  dst_elt->indx = a_elt->indx;
	  for (ix = BITMAP_ELEMENT_WORDS; ix--;)
	    {
	      BITMAP_WORD r = a_elt->bits[ix] ^ b_elt->bits[ix];

	      ior |= r;
	      dst_elt->bits[ix] = r;
	    }
	  a_elt = a_elt->next;
	  b_elt = b_elt->next;
	  if (ior)
	    {
	      dst_prev = dst_elt;
	      dst_elt = dst_elt->next;
	    }
	}
      else
	{
	  /* Copy a single element.  */
	  bitmap_element *src;

	  if (!b_elt || (a_elt && a_elt->indx < b_elt->indx))
	    {
	      src = a_elt;
	      a_elt = a_elt->next;
	    }
	  else
	    {
	      src = b_elt;
	      b_elt = b_elt->next;
	    }

	  if (!dst_elt)
	    dst_elt = bitmap_elt_insert_after (dst, dst_prev);
	  
	  dst_elt->indx = src->indx;
	  memcpy (dst_elt->bits, src->bits, sizeof (dst_elt->bits));
	  dst_prev = dst_elt;
	  dst_elt = dst_elt->next;
	}
    }
  bitmap_elt_clear_from (dst, dst_elt);
  gcc_assert (!dst->current == !dst->first);
  if (dst->current)
    dst->indx = dst->current->indx;
}

/* A ^= B */

void
bitmap_xor_into (bitmap a, bitmap b)
{
  bitmap_element *a_elt = a->first;
  bitmap_element *b_elt = b->first;
  bitmap_element *a_prev = NULL;

  if (a == b)
    {
      bitmap_clear (a);
      return;
    }

  while (b_elt)
    {
      if (!a_elt || b_elt->indx < a_elt->indx)
	{
	  /* Copy b_elt.  */
	  bitmap_element *dst = bitmap_elt_insert_after (a, a_prev);
	  
	  dst->indx = b_elt->indx;
	  memcpy (dst->bits, b_elt->bits, sizeof (dst->bits));
	  a_prev = dst;
	  b_elt = b_elt->next;
	}
      else if (a_elt->indx < b_elt->indx)
	{
	  a_prev = a_elt;
	  a_elt = a_elt->next;
	}
      else
	{
	  /* Matching elts, generate A ^= B.  */
	  unsigned ix;
	  BITMAP_WORD ior = 0;
	  bitmap_element *next = a_elt->next;

	  for (ix = BITMAP_ELEMENT_WORDS; ix--;)
	    {
	      BITMAP_WORD r = a_elt->bits[ix] ^ b_elt->bits[ix];

	      ior |= r;
	      a_elt->bits[ix] = r;
	    }
	  b_elt = b_elt->next;
	  if (ior)
	    a_prev = a_elt;
	  else
	    bitmap_element_free (a, a_elt);
	  a_elt = next;
	}
    }
  gcc_assert (!a->current == !a->first);
  if (a->current)
    a->indx = a->current->indx;
}

/* Return true if two bitmaps are identical.
   We do not bother with a check for pointer equality, as that never
   occurs in practice.  */

bool
bitmap_equal_p (bitmap a, bitmap b)
{
  bitmap_element *a_elt;
  bitmap_element *b_elt;
  unsigned ix;
  
  for (a_elt = a->first, b_elt = b->first;
       a_elt && b_elt;
       a_elt = a_elt->next, b_elt = b_elt->next)
    {
      if (a_elt->indx != b_elt->indx)
	return false;
      for (ix = BITMAP_ELEMENT_WORDS; ix--;)
	if (a_elt->bits[ix] != b_elt->bits[ix])
	  return false;
    }
  return !a_elt && !b_elt;
}

/* Return true if A AND B is not empty.  */

bool
bitmap_intersect_p (bitmap a, bitmap b)
{
  bitmap_element *a_elt;
  bitmap_element *b_elt;
  unsigned ix;
  
  for (a_elt = a->first, b_elt = b->first;
       a_elt && b_elt;)
    {
      if (a_elt->indx < b_elt->indx)
	a_elt = a_elt->next;
      else if (b_elt->indx < a_elt->indx)
	b_elt = b_elt->next;
      else
	{
	  for (ix = BITMAP_ELEMENT_WORDS; ix--;)
	    if (a_elt->bits[ix] & b_elt->bits[ix])
	      return true;
	  a_elt = a_elt->next;
	  b_elt = b_elt->next;
	}
    }
  return false;
}

/* Return true if A AND NOT B is not empty.  */

bool
bitmap_intersect_compl_p (bitmap a, bitmap b)
{
  bitmap_element *a_elt;
  bitmap_element *b_elt;
  unsigned ix;
  for (a_elt = a->first, b_elt = b->first;
       a_elt && b_elt;)
    {
      if (a_elt->indx < b_elt->indx)
	return true;
      else if (b_elt->indx < a_elt->indx)
	b_elt = b_elt->next;
      else
	{
	  for (ix = BITMAP_ELEMENT_WORDS; ix--;)
	    if (a_elt->bits[ix] & ~b_elt->bits[ix])
	      return true;
	  a_elt = a_elt->next;
	  b_elt = b_elt->next;
	}
    }
  return a_elt != NULL;
}


/* DST = A | (FROM1 & ~FROM2).  Return true if DST changes.  */

bool
bitmap_ior_and_compl (bitmap dst, bitmap a, bitmap from1, bitmap from2)
{
  bitmap_head tmp;
  bool changed;

  bitmap_initialize (&tmp, &bitmap_default_obstack);
  bitmap_and_compl (&tmp, from1, from2);
  changed = bitmap_ior (dst, a, &tmp);
  bitmap_clear (&tmp);

  return changed;
}

/* A |= (FROM1 & ~FROM2).  Return true if A changes.  */

bool
bitmap_ior_and_compl_into (bitmap a, bitmap from1, bitmap from2)
{
  bitmap_head tmp;
  bool changed;
  
  bitmap_initialize (&tmp, &bitmap_default_obstack);
  bitmap_and_compl (&tmp, from1, from2);
  changed = bitmap_ior_into (a, &tmp);
  bitmap_clear (&tmp);

  return changed;
}

/* Debugging function to print out the contents of a bitmap.  */

void
debug_bitmap_file (FILE *file, bitmap head)
{
  bitmap_element *ptr;

  fprintf (file, "\nfirst = " HOST_PTR_PRINTF
	   " current = " HOST_PTR_PRINTF " indx = %u\n",
	   (void *) head->first, (void *) head->current, head->indx);

  for (ptr = head->first; ptr; ptr = ptr->next)
    {
      unsigned int i, j, col = 26;

      fprintf (file, "\t" HOST_PTR_PRINTF " next = " HOST_PTR_PRINTF
	       " prev = " HOST_PTR_PRINTF " indx = %u\n\t\tbits = {",
	       (void*) ptr, (void*) ptr->next, (void*) ptr->prev, ptr->indx);

      for (i = 0; i < BITMAP_ELEMENT_WORDS; i++)
	for (j = 0; j < BITMAP_WORD_BITS; j++)
	  if ((ptr->bits[i] >> j) & 1)
	    {
	      if (col > 70)
		{
		  fprintf (file, "\n\t\t\t");
		  col = 24;
		}

	      fprintf (file, " %u", (ptr->indx * BITMAP_ELEMENT_ALL_BITS
				     + i * BITMAP_WORD_BITS + j));
	      col += 4;
	    }

      fprintf (file, " }\n");
    }
}

/* Function to be called from the debugger to print the contents
   of a bitmap.  */

void
debug_bitmap (bitmap head)
{
  debug_bitmap_file (stdout, head);
}

/* Function to print out the contents of a bitmap.  Unlike debug_bitmap_file,
   it does not print anything but the bits.  */

void
bitmap_print (FILE *file, bitmap head, const char *prefix, const char *suffix)
{
  const char *comma = "";
  unsigned i;
  bitmap_iterator bi;

  fputs (prefix, file);
  EXECUTE_IF_SET_IN_BITMAP (head, 0, i, bi)
    {
      fprintf (file, "%s%d", comma, i);
      comma = ", ";
    }
  fputs (suffix, file);
}

#include "gt-bitmap.h"
