/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 *
 * Copyright (c) 1996-1998
 * Silicon Graphics Computer Systems, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Silicon Graphics makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */

/* NOTE: This is an internal header file, included by other STL headers.
 *   You should not attempt to use it directly.
 */

#ifndef __SGI_STL_INTERNAL_ITERATOR_H
#define __SGI_STL_INTERNAL_ITERATOR_H

namespace std
{
  // 24.4.1 Reverse iterators
  template<typename _Iterator>
    class reverse_iterator 
      : public iterator<typename iterator_traits<_Iterator>::iterator_category,
			typename iterator_traits<_Iterator>::value_type,
		        typename iterator_traits<_Iterator>::difference_type,
		        typename iterator_traits<_Iterator>::pointer,
                        typename iterator_traits<_Iterator>::reference>
    {
    protected:
      _Iterator _M_current;

    public:
      typedef _Iterator 				       iterator_type;
      typedef typename iterator_traits<_Iterator>::difference_type 	
      							       difference_type;
      typedef typename iterator_traits<_Iterator>::reference   reference;
      typedef typename iterator_traits<_Iterator>::pointer     pointer;

    public:
      reverse_iterator() {}

      explicit 
      reverse_iterator(iterator_type __x) : _M_current(__x) {}

      reverse_iterator(const reverse_iterator& __x) 
	: _M_current(__x._M_current) { }

      template<typename _Iter>
        reverse_iterator(const reverse_iterator<_Iter>& __x)
	: _M_current(__x.base()) {}
    
      iterator_type 
      base() const { return _M_current; }

      reference 
      operator*() const 
      {
	_Iterator __tmp = _M_current;
	return *--__tmp;
      }

      pointer 
      operator->() const { return &(operator*()); }

      reverse_iterator& 
      operator++() 
      {
	--_M_current;
	return *this;
      }

      reverse_iterator 
      operator++(int) 
      {
	reverse_iterator __tmp = *this;
	--_M_current;
	return __tmp;
      }

      reverse_iterator& 
      operator--() 
      {
	++_M_current;
	return *this;
      }

      reverse_iterator operator--(int) 
      {
	reverse_iterator __tmp = *this;
	++_M_current;
	return __tmp;
      }
      
      reverse_iterator 
      operator+(difference_type __n) const 
      { return reverse_iterator(_M_current - __n); }

      reverse_iterator& 
      operator+=(difference_type __n) 
      {
	_M_current -= __n;
	return *this;
      }

      reverse_iterator 
      operator-(difference_type __n) const 
      { return reverse_iterator(_M_current + __n); }

      reverse_iterator& 
      operator-=(difference_type __n) 
      {
	_M_current += __n;
	return *this;
      }

      reference 
      operator[](difference_type __n) const { return *(*this + __n); }  
    }; 
 
  template<typename _Iterator>
    inline bool 
    operator==(const reverse_iterator<_Iterator>& __x, 
	       const reverse_iterator<_Iterator>& __y) 
    { return __x.base() == __y.base(); }

  template<typename _Iterator>
    inline bool 
    operator<(const reverse_iterator<_Iterator>& __x, 
	      const reverse_iterator<_Iterator>& __y) 
    { return __y.base() < __x.base(); }

  template<typename _Iterator>
    inline bool 
    operator!=(const reverse_iterator<_Iterator>& __x, 
	       const reverse_iterator<_Iterator>& __y) 
    { return !(__x == __y); }

  template<typename _Iterator>
    inline bool 
    operator>(const reverse_iterator<_Iterator>& __x, 
	      const reverse_iterator<_Iterator>& __y) 
    { return __y < __x; }

  template<typename _Iterator>
    inline bool 
    operator<=(const reverse_iterator<_Iterator>& __x, 
		const reverse_iterator<_Iterator>& __y) 
    { return !(__y < __x); }

  template<typename _Iterator>
    inline bool 
    operator>=(const reverse_iterator<_Iterator>& __x, 
	       const reverse_iterator<_Iterator>& __y) 
    { return !(__x < __y); }

  template<typename _Iterator>
    inline typename reverse_iterator<_Iterator>::difference_type
    operator-(const reverse_iterator<_Iterator>& __x, 
	      const reverse_iterator<_Iterator>& __y) 
    { return __y.base() - __x.base(); }

  template<typename _Iterator>
    inline reverse_iterator<_Iterator> 
    operator+(typename reverse_iterator<_Iterator>::difference_type __n,
	      const reverse_iterator<_Iterator>& __x) 
    { return reverse_iterator<_Iterator>(__x.base() - __n); }

  // 24.4.2.2.1 back_insert_iterator
  template<typename _Container>
  class back_insert_iterator 
    : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _Container* container;

    public:
      typedef _Container          container_type;
      
      explicit 
      back_insert_iterator(_Container& __x) : container(&__x) {}

      back_insert_iterator<_Container>&
      operator=(const typename _Container::value_type& __value) 
      { 
	container->push_back(__value);
	return *this;
      }

      back_insert_iterator<_Container>& 
      operator*() { return *this; }

      back_insert_iterator<_Container>& 
      operator++() { return *this; }

      back_insert_iterator<_Container>& 
      operator++(int) { return *this; }
    };

  template<typename _Container>
    inline back_insert_iterator<_Container> 
    back_inserter(_Container& __x) 
    { return back_insert_iterator<_Container>(__x); }

  template<typename _Container>
    class front_insert_iterator 
      : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _Container* container;

    public:
      typedef _Container          container_type;

      explicit front_insert_iterator(_Container& __x) : container(&__x) {}
      front_insert_iterator<_Container>&
      operator=(const typename _Container::value_type& __value) { 
	container->push_front(__value);
	return *this;
      }
      front_insert_iterator<_Container>& operator*() { return *this; }
      front_insert_iterator<_Container>& operator++() { return *this; }
      front_insert_iterator<_Container>& operator++(int) { return *this; }
    };

  template<typename _Container>
  inline front_insert_iterator<_Container> front_inserter(_Container& __x) 
  { return front_insert_iterator<_Container>(__x); }

  template<typename _Container>
    class insert_iterator 
      : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _Container* container;
      typename _Container::iterator iter;

    public:
      typedef _Container          container_type;
      
      insert_iterator(_Container& __x, typename _Container::iterator __i) 
	: container(&__x), iter(__i) {}
   
      insert_iterator<_Container>&
      operator=(const typename _Container::value_type& __value) { 
	iter = container->insert(iter, __value);
	++iter;
	return *this;
      }
      insert_iterator<_Container>& operator*() { return *this; }
      insert_iterator<_Container>& operator++() { return *this; }
      insert_iterator<_Container>& operator++(int) { return *this; }
    };
  
  template<typename _Container, typename _Iterator>
    inline 
    insert_iterator<_Container> inserter(_Container& __x, _Iterator __i)
    {
      typedef typename _Container::iterator __iter;
      return insert_iterator<_Container>(__x, __iter(__i));
    }
  

  template<typename _Tp, typename _CharT = char, 
           typename _Traits = char_traits<_CharT>, typename _Dist = ptrdiff_t> 
    class istream_iterator 
      : public iterator<input_iterator_tag, _Tp, _Dist, const _Tp*, const _Tp&>
    {
    public:
      typedef _CharT                         char_type;
      typedef _Traits                        traits_type;
      typedef basic_istream<_CharT, _Traits> istream_type;

    private:
      istream_type* 	_M_stream;
      _Tp 		_M_value;
      bool 		_M_ok;

    public:      
      istream_iterator() : _M_stream(0), _M_ok(false) {}
      istream_iterator(istream_type& __s) : _M_stream(&__s) { _M_read(); }

      reference 
      operator*() const { return _M_value; }

      pointer 
      operator->() const { return &(operator*()); }

      istream_iterator& 
      operator++() 
      { _M_read(); return *this; }

      istream_iterator 
      operator++(int)  
      {
	istream_iterator __tmp = *this;
	_M_read();
	return __tmp;
      }

      bool 
      _M_equal(const istream_iterator& __x) const
      { return (_M_ok == __x._M_ok) && (!_M_ok || _M_stream == __x._M_stream);}

    private:      
      void _M_read() 
      {
	_M_ok = (_M_stream && *_M_stream) ? true : false;
	if (_M_ok) 
	  {
	    *_M_stream >> _M_value;
	    _M_ok = *_M_stream ? true : false;
	  }
      }
    };
  
  template<typename _Tp, typename _CharT, typename _Traits, typename _Dist>
    inline bool 
    operator==(const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __x,
	       const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __y) 
    { return __x._M_equal(__y); }

  template <class _Tp, class _CharT, class _Traits, class _Dist>
    inline bool 
  operator!=(const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __x,
	     const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __y) 
  { return !__x._M_equal(__y); }


  template<typename _Tp, typename _CharT = char, 
           typename _Traits = char_traits<_CharT> >
    class ostream_iterator 
      : public iterator<output_iterator_tag, void, void, void, void>
    {
    public:
      typedef _CharT                         char_type;
      typedef _Traits                        traits_type;
      typedef basic_ostream<_CharT, _Traits> ostream_type;

    private:
      ostream_type* 	_M_stream;
      const _CharT* 	_M_string;

    public:
      ostream_iterator(ostream_type& __s) : _M_stream(&__s), _M_string(0) {}
      ostream_iterator(ostream_type& __s, const _CharT* __c) 
	: _M_stream(&__s), _M_string(__c)  { }

      ostream_iterator& 
      operator=(const _Tp& __value) 
      { 
	*_M_stream << __value;
	if (_M_string) *_M_stream << _M_string;
	return *this;
      }
      
      ostream_iterator& 
      operator*() { return *this; }
      
      ostream_iterator& 
      operator++() { return *this; } 
      
      ostream_iterator& 
      operator++(int) { return *this; } 
    };
  
  
  // This iterator adapter is 'normal' in the sense that it does not
  // change the semantics of any of the operators of its itererator
  // parameter.  Its primary purpose is to convert an iterator that is
  // not a class, e.g. a pointer, into an iterator that is a class.
  // The _Container parameter exists solely so that different containers
  // using this template can instantiate different types, even if the
  // _Iterator parameter is the same.
  template<typename _Iterator, typename _Container>
    class __normal_iterator
      : public iterator<typename iterator_traits<_Iterator>::iterator_category,
                        typename iterator_traits<_Iterator>::value_type,
                        typename iterator_traits<_Iterator>::difference_type,
                        typename iterator_traits<_Iterator>::pointer,
                        typename iterator_traits<_Iterator>::reference>
    {
    protected:
      _Iterator _M_current;
      
    public:
      typedef typename iterator_traits<_Iterator>::difference_type 	
      							       difference_type;
      typedef typename iterator_traits<_Iterator>::reference   reference;
      typedef typename iterator_traits<_Iterator>::pointer     pointer;

      __normal_iterator() : _M_current(_Iterator()) { }

      explicit 
      __normal_iterator(const _Iterator& __i) : _M_current(__i) { }

      // Allow iterator to const_iterator conversion
      template<typename _Iter>
      inline __normal_iterator(const __normal_iterator<_Iter, _Container>& __i)
	: _M_current(__i.base()) { }

      // Forward iterator requirements
      reference
      operator*() const { return *_M_current; }
      
      pointer
      operator->() const { return _M_current; }
      
      __normal_iterator&
      operator++() { ++_M_current; return *this; }
      
      __normal_iterator
      operator++(int) { return __normal_iterator(_M_current++); }
      
      // Bidirectional iterator requirements
      __normal_iterator&
      operator--() { --_M_current; return *this; }
      
      __normal_iterator
      operator--(int) { return __normal_iterator(_M_current--); }
      
      // Random access iterator requirements
      reference
      operator[](const difference_type& __n) const
      { return _M_current[__n]; }
      
      __normal_iterator&
      operator+=(const difference_type& __n)
      { _M_current += __n; return *this; }

      __normal_iterator
      operator+(const difference_type& __n) const
      { return __normal_iterator(_M_current + __n); }
      
      __normal_iterator&
      operator-=(const difference_type& __n)
      { _M_current -= __n; return *this; }
      
      __normal_iterator
      operator-(const difference_type& __n) const
      { return __normal_iterator(_M_current - __n); }
      
      difference_type
      operator-(const __normal_iterator& __i) const
      { return _M_current - __i._M_current; }
      
      const _Iterator& 
      base() const { return _M_current; }
    };

  // Forward iterator requirements
  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator==(const __normal_iterator<_IteratorL, _Container>& __lhs,
	     const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return __lhs.base() == __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator!=(const __normal_iterator<_IteratorL, _Container>& __lhs,
	     const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return !(__lhs == __rhs); }

  // Random access iterator requirements
  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool 
  operator<(const __normal_iterator<_IteratorL, _Container>& __lhs,
	    const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return __lhs.base() < __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator>(const __normal_iterator<_IteratorL, _Container>& __lhs,
	    const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return __rhs < __lhs; }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator<=(const __normal_iterator<_IteratorL, _Container>& __lhs,
	     const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return !(__rhs < __lhs); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator>=(const __normal_iterator<_IteratorL, _Container>& __lhs,
	     const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return !(__lhs < __rhs); }

  template<typename _Iterator, typename _Container>
  inline __normal_iterator<_Iterator, _Container>
  operator+(__normal_iterator<_Iterator, _Container>::difference_type __n,
	    const __normal_iterator<_Iterator, _Container>& __i)
  { return __normal_iterator<_Iterator, _Container>(__i.base() + __n); }
} // namespace std

#endif 

// Local Variables:
// mode:C++
// End:
