// AUTO-GENERATED by autogen.sh; DO NOT EDIT

#include "runtime.h"
#include "arch.h"
#include "go-type.h"
#include "race.h"
#include "malloc.h"
#include "chan.h"

#line 13 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
uint32 runtime_Hchansize = sizeof ( Hchan ) ; 
#line 15 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void dequeueg ( WaitQ* ) ; 
static SudoG* dequeue ( WaitQ* ) ; 
static void enqueue ( WaitQ* , SudoG* ) ; 
static void racesync ( Hchan* , SudoG* ) ; 
#line 20 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static Hchan* 
makechan ( ChanType *t , int64 hint ) 
{ 
Hchan *c; 
uintptr n; 
const Type *elem; 
#line 27 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
elem = t->__element_type; 
#line 30 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( elem->__size >= ( 1<<16 ) ) 
runtime_throw ( "makechan: invalid channel element type" ) ; 
#line 33 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( hint < 0 || ( intgo ) hint != hint || ( elem->__size > 0 && ( uintptr ) hint > ( MaxMem - sizeof ( *c ) ) / elem->__size ) ) 
runtime_panicstring ( "makechan: size out of range" ) ; 
#line 36 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
n = sizeof ( *c ) ; 
n = ROUND ( n , elem->__align ) ; 
#line 40 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
c = ( Hchan* ) runtime_mallocgc ( sizeof ( *c ) + hint*elem->__size , ( uintptr ) t | TypeInfo_Chan , 0 ) ; 
c->elemsize = elem->__size; 
c->elemtype = elem; 
c->dataqsiz = hint; 
#line 45 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( debug ) 
runtime_printf ( "makechan: chan=%p; elemsize=%D; dataqsiz=%D\n" , 
c , ( int64 ) elem->__size , ( int64 ) c->dataqsiz ) ; 
#line 49 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
return c; 
} 
Hchan* reflect_makechan(ChanType* t, uint64 size) __asm__ (GOSYM_PREFIX "reflect.makechan");
Hchan* reflect_makechan(ChanType* t, uint64 size)
{
  Hchan* c;
#line 52 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	c = makechan(t, size);
return c;
}

#line 56 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
Hchan* 
__go_new_channel ( ChanType *t , uintptr hint ) 
{ 
return makechan ( t , hint ) ; 
} 
#line 62 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
Hchan* 
__go_new_channel_big ( ChanType *t , uint64 hint ) 
{ 
return makechan ( t , hint ) ; 
} 
#line 82 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static bool 
chansend ( ChanType *t , Hchan *c , byte *ep , bool block , void *pc ) 
{ 
SudoG *sg; 
SudoG mysg; 
G* gp; 
int64 t0; 
G* g; 
#line 91 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
g = runtime_g ( ) ; 
#line 93 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( raceenabled ) 
runtime_racereadobjectpc ( ep , t->__element_type , runtime_getcallerpc ( &t ) , chansend ) ; 
#line 96 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( c == nil ) { 
USED ( t ) ; 
if ( !block ) 
return false; 
runtime_park ( nil , nil , "chan send (nil chan)" ) ; 
return false; 
} 
#line 104 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( runtime_gcwaiting ( ) ) 
runtime_gosched ( ) ; 
#line 107 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( debug ) { 
runtime_printf ( "chansend: chan=%p\n" , c ) ; 
} 
#line 111 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
t0 = 0; 
mysg.releasetime = 0; 
if ( runtime_blockprofilerate > 0 ) { 
t0 = runtime_cputicks ( ) ; 
mysg.releasetime = -1; 
} 
#line 118 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
runtime_lock ( c ) ; 
if ( raceenabled ) 
runtime_racereadpc ( c , pc , chansend ) ; 
if ( c->closed ) 
goto closed; 
#line 124 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( c->dataqsiz > 0 ) 
goto asynch; 
#line 127 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
sg = dequeue ( &c->recvq ) ; 
if ( sg != nil ) { 
if ( raceenabled ) 
racesync ( c , sg ) ; 
runtime_unlock ( c ) ; 
#line 133 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
gp = sg->g; 
gp->param = sg; 
if ( sg->elem != nil ) 
runtime_memmove ( sg->elem , ep , c->elemsize ) ; 
if ( sg->releasetime ) 
sg->releasetime = runtime_cputicks ( ) ; 
runtime_ready ( gp ) ; 
return true; 
} 
#line 143 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( !block ) { 
runtime_unlock ( c ) ; 
return false; 
} 
#line 148 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
mysg.elem = ep; 
mysg.g = g; 
mysg.selectdone = nil; 
g->param = nil; 
enqueue ( &c->sendq , &mysg ) ; 
runtime_parkunlock ( c , "chan send" ) ; 
#line 155 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( g->param == nil ) { 
runtime_lock ( c ) ; 
if ( !c->closed ) 
runtime_throw ( "chansend: spurious wakeup" ) ; 
goto closed; 
} 
#line 162 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( mysg.releasetime > 0 ) 
runtime_blockevent ( mysg.releasetime - t0 , 2 ) ; 
#line 165 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
return true; 
#line 167 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
asynch: 
if ( c->closed ) 
goto closed; 
#line 171 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( c->qcount >= c->dataqsiz ) { 
if ( !block ) { 
runtime_unlock ( c ) ; 
return false; 
} 
mysg.g = g; 
mysg.elem = nil; 
mysg.selectdone = nil; 
enqueue ( &c->sendq , &mysg ) ; 
runtime_parkunlock ( c , "chan send" ) ; 
#line 182 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
runtime_lock ( c ) ; 
goto asynch; 
} 
#line 186 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( raceenabled ) 
runtime_racerelease ( chanbuf ( c , c->sendx ) ) ; 
#line 189 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
runtime_memmove ( chanbuf ( c , c->sendx ) , ep , c->elemsize ) ; 
if ( ++c->sendx == c->dataqsiz ) 
c->sendx = 0; 
c->qcount++; 
#line 194 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
sg = dequeue ( &c->recvq ) ; 
if ( sg != nil ) { 
gp = sg->g; 
runtime_unlock ( c ) ; 
if ( sg->releasetime ) 
sg->releasetime = runtime_cputicks ( ) ; 
runtime_ready ( gp ) ; 
} else 
runtime_unlock ( c ) ; 
if ( mysg.releasetime > 0 ) 
runtime_blockevent ( mysg.releasetime - t0 , 2 ) ; 
return true; 
#line 207 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
closed: 
runtime_unlock ( c ) ; 
runtime_panicstring ( "send on closed channel" ) ; 
return false; 
} 
#line 214 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static bool 
chanrecv ( ChanType *t , Hchan* c , byte *ep , bool block , bool *received ) 
{ 
SudoG *sg; 
SudoG mysg; 
G *gp; 
int64 t0; 
G *g; 
#line 223 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( runtime_gcwaiting ( ) ) 
runtime_gosched ( ) ; 
#line 228 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( debug ) 
runtime_printf ( "chanrecv: chan=%p\n" , c ) ; 
#line 231 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
g = runtime_g ( ) ; 
#line 233 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( c == nil ) { 
USED ( t ) ; 
if ( !block ) 
return false; 
runtime_park ( nil , nil , "chan receive (nil chan)" ) ; 
return false; 
} 
#line 241 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
t0 = 0; 
mysg.releasetime = 0; 
if ( runtime_blockprofilerate > 0 ) { 
t0 = runtime_cputicks ( ) ; 
mysg.releasetime = -1; 
} 
#line 248 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
runtime_lock ( c ) ; 
if ( c->dataqsiz > 0 ) 
goto asynch; 
#line 252 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( c->closed ) 
goto closed; 
#line 255 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
sg = dequeue ( &c->sendq ) ; 
if ( sg != nil ) { 
if ( raceenabled ) 
racesync ( c , sg ) ; 
runtime_unlock ( c ) ; 
#line 261 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( ep != nil ) 
runtime_memmove ( ep , sg->elem , c->elemsize ) ; 
gp = sg->g; 
gp->param = sg; 
if ( sg->releasetime ) 
sg->releasetime = runtime_cputicks ( ) ; 
runtime_ready ( gp ) ; 
#line 269 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( received != nil ) 
*received = true; 
return true; 
} 
#line 274 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( !block ) { 
runtime_unlock ( c ) ; 
return false; 
} 
#line 279 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
mysg.elem = ep; 
mysg.g = g; 
mysg.selectdone = nil; 
g->param = nil; 
enqueue ( &c->recvq , &mysg ) ; 
runtime_parkunlock ( c , "chan receive" ) ; 
#line 286 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( g->param == nil ) { 
runtime_lock ( c ) ; 
if ( !c->closed ) 
runtime_throw ( "chanrecv: spurious wakeup" ) ; 
goto closed; 
} 
#line 293 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( received != nil ) 
*received = true; 
if ( mysg.releasetime > 0 ) 
runtime_blockevent ( mysg.releasetime - t0 , 2 ) ; 
return true; 
#line 299 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
asynch: 
if ( c->qcount <= 0 ) { 
if ( c->closed ) 
goto closed; 
#line 304 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( !block ) { 
runtime_unlock ( c ) ; 
if ( received != nil ) 
*received = false; 
return false; 
} 
mysg.g = g; 
mysg.elem = nil; 
mysg.selectdone = nil; 
enqueue ( &c->recvq , &mysg ) ; 
runtime_parkunlock ( c , "chan receive" ) ; 
#line 316 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
runtime_lock ( c ) ; 
goto asynch; 
} 
#line 320 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( raceenabled ) 
runtime_raceacquire ( chanbuf ( c , c->recvx ) ) ; 
#line 323 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( ep != nil ) 
runtime_memmove ( ep , chanbuf ( c , c->recvx ) , c->elemsize ) ; 
runtime_memclr ( chanbuf ( c , c->recvx ) , c->elemsize ) ; 
if ( ++c->recvx == c->dataqsiz ) 
c->recvx = 0; 
c->qcount--; 
#line 330 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
sg = dequeue ( &c->sendq ) ; 
if ( sg != nil ) { 
gp = sg->g; 
runtime_unlock ( c ) ; 
if ( sg->releasetime ) 
sg->releasetime = runtime_cputicks ( ) ; 
runtime_ready ( gp ) ; 
} else 
runtime_unlock ( c ) ; 
#line 340 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( received != nil ) 
*received = true; 
if ( mysg.releasetime > 0 ) 
runtime_blockevent ( mysg.releasetime - t0 , 2 ) ; 
return true; 
#line 346 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
closed: 
if ( ep != nil ) 
runtime_memclr ( ep , c->elemsize ) ; 
if ( received != nil ) 
*received = false; 
if ( raceenabled ) 
runtime_raceacquire ( c ) ; 
runtime_unlock ( c ) ; 
if ( mysg.releasetime > 0 ) 
runtime_blockevent ( mysg.releasetime - t0 , 2 ) ; 
return true; 
} 
#line 361 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
void 
__go_send_small ( ChanType *t , Hchan* c , uint64 val ) 
{ 
union 
{ 
byte b[sizeof ( uint64 ) ]; 
uint64 v; 
} u; 
byte *v; 
#line 371 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
u.v = val; 
#ifndef WORDS_BIGENDIAN 
v = u.b; 
#else 
v = u.b + sizeof ( uint64 ) - t->__element_type->__size; 
#endif 
chansend ( t , c , v , true , runtime_getcallerpc ( &t ) ) ; 
} 
#line 382 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
void 
__go_send_big ( ChanType *t , Hchan* c , byte* v ) 
{ 
chansend ( t , c , v , true , runtime_getcallerpc ( &t ) ) ; 
} 
#line 390 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
void 
__go_receive ( ChanType *t , Hchan* c , byte* v ) 
{ 
chanrecv ( t , c , v , true , nil ) ; 
} 
#line 396 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
_Bool runtime_chanrecv2 ( ChanType *t , Hchan* c , byte* v ) 
__asm__ ( GOSYM_PREFIX "runtime.chanrecv2" ) ; 
#line 399 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
_Bool 
runtime_chanrecv2 ( ChanType *t , Hchan* c , byte* v ) 
{ 
bool received = false; 
#line 404 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
chanrecv ( t , c , v , true , &received ) ; 
return received; 
} 
bool runtime_selectnbsend(ChanType* t, Hchan* c, byte* elem) __asm__ (GOSYM_PREFIX "runtime.selectnbsend");
bool runtime_selectnbsend(ChanType* t, Hchan* c, byte* elem)
{
  bool selected;
#line 425 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	selected = chansend(t, c, elem, false, runtime_getcallerpc(&t));
return selected;
}
bool runtime_selectnbrecv(ChanType* t, byte* elem, Hchan* c) __asm__ (GOSYM_PREFIX "runtime.selectnbrecv");
bool runtime_selectnbrecv(ChanType* t, byte* elem, Hchan* c)
{
  bool selected;
#line 446 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	selected = chanrecv(t, c, elem, false, nil);
return selected;
}
bool runtime_selectnbrecv2(ChanType* t, byte* elem, bool* received, Hchan* c) __asm__ (GOSYM_PREFIX "runtime.selectnbrecv2");
bool runtime_selectnbrecv2(ChanType* t, byte* elem, bool* received, Hchan* c)
{
  bool selected;
#line 467 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	bool r;

	selected = chanrecv(t, c, elem, false, received == nil ? nil : &r);
	if(received != nil)
		*received = r;
return selected;
}
bool reflect_chansend(ChanType* t, Hchan* c, byte* elem, bool nb) __asm__ (GOSYM_PREFIX "reflect.chansend");
bool reflect_chansend(ChanType* t, Hchan* c, byte* elem, bool nb)
{
  bool selected;
#line 475 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	selected = chansend(t, c, elem, !nb, runtime_getcallerpc(&t));
return selected;
}
struct reflect_chanrecv_ret {
  bool selected;
  bool received;
};
struct reflect_chanrecv_ret reflect_chanrecv(ChanType* t, Hchan* c, bool nb, byte* elem) __asm__ (GOSYM_PREFIX "reflect.chanrecv");
struct reflect_chanrecv_ret reflect_chanrecv(ChanType* t, Hchan* c, bool nb, byte* elem)
{
  bool selected;
  bool received;
#line 479 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	received = false;
	selected = chanrecv(t, c, elem, !nb, &received);
  {
    struct reflect_chanrecv_ret __ret;
    __ret.selected = selected;
    __ret.received = received;
    return __ret;
  }
}

#line 484 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static Select* newselect ( int32 ) ; 
byte* runtime_newselect(int32 size) __asm__ (GOSYM_PREFIX "runtime.newselect");
byte* runtime_newselect(int32 size)
{
  byte* sel;
#line 486 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

 	sel = (byte*)newselect(size);
return sel;
}

#line 490 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static Select* 
newselect ( int32 size ) 
{ 
int32 n; 
Select *sel; 
#line 496 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
n = 0; 
if ( size > 1 ) 
n = size-1; 
#line 504 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
sel = runtime_mal ( sizeof ( *sel ) + 
n*sizeof ( sel->scase[0] ) + 
size*sizeof ( sel->lockorder[0] ) + 
size*sizeof ( sel->pollorder[0] ) ) ; 
#line 509 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
sel->tcase = size; 
sel->ncase = 0; 
sel->lockorder = ( void* ) ( sel->scase + size ) ; 
sel->pollorder = ( void* ) ( sel->lockorder + size ) ; 
#line 514 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( debug ) 
runtime_printf ( "newselect s=%p size=%d\n" , sel , size ) ; 
return sel; 
} 
#line 520 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void selectsend ( Select *sel , Hchan *c , int index , void *elem ) ; 
void runtime_selectsend(Select* sel, Hchan* c, byte* elem, int32 index) __asm__ (GOSYM_PREFIX "runtime.selectsend");
void runtime_selectsend(Select* sel, Hchan* c, byte* elem, int32 index)
{
#line 522 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	// nil cases do not compete
	if(c != nil)
		selectsend(sel, c, index, elem);
}

#line 528 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void 
selectsend ( Select *sel , Hchan *c , int index , void *elem ) 
{ 
int32 i; 
Scase *cas; 
#line 534 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
i = sel->ncase; 
if ( i >= sel->tcase ) 
runtime_throw ( "selectsend: too many cases" ) ; 
sel->ncase = i+1; 
cas = &sel->scase[i]; 
#line 540 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
cas->index = index; 
cas->chan = c; 
cas->kind = CaseSend; 
cas->sg.elem = elem; 
#line 545 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( debug ) 
runtime_printf ( "selectsend s=%p index=%d chan=%p\n" , 
sel , cas->index , cas->chan ) ; 
} 
#line 551 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void selectrecv ( Select *sel , Hchan *c , int index , void *elem , bool* ) ; 
void runtime_selectrecv(Select* sel, Hchan* c, byte* elem, int32 index) __asm__ (GOSYM_PREFIX "runtime.selectrecv");
void runtime_selectrecv(Select* sel, Hchan* c, byte* elem, int32 index)
{
#line 553 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	// nil cases do not compete
	if(c != nil)
		selectrecv(sel, c, index, elem, nil);
}
void runtime_selectrecv2(Select* sel, Hchan* c, byte* elem, bool* received, int32 index) __asm__ (GOSYM_PREFIX "runtime.selectrecv2");
void runtime_selectrecv2(Select* sel, Hchan* c, byte* elem, bool* received, int32 index)
{
#line 559 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	// nil cases do not compete
	if(c != nil)
		selectrecv(sel, c, index, elem, received);
}

#line 565 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void 
selectrecv ( Select *sel , Hchan *c , int index , void *elem , bool *received ) 
{ 
int32 i; 
Scase *cas; 
#line 571 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
i = sel->ncase; 
if ( i >= sel->tcase ) 
runtime_throw ( "selectrecv: too many cases" ) ; 
sel->ncase = i+1; 
cas = &sel->scase[i]; 
cas->index = index; 
cas->chan = c; 
#line 579 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
cas->kind = CaseRecv; 
cas->sg.elem = elem; 
cas->receivedp = received; 
#line 583 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( debug ) 
runtime_printf ( "selectrecv s=%p index=%d chan=%p\n" , 
sel , cas->index , cas->chan ) ; 
} 
#line 589 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void selectdefault ( Select* , int ) ; 
void runtime_selectdefault(Select* sel, int32 index) __asm__ (GOSYM_PREFIX "runtime.selectdefault");
void runtime_selectdefault(Select* sel, int32 index)
{
#line 591 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	selectdefault(sel, index);
}

#line 595 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void 
selectdefault ( Select *sel , int32 index ) 
{ 
int32 i; 
Scase *cas; 
#line 601 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
i = sel->ncase; 
if ( i >= sel->tcase ) 
runtime_throw ( "selectdefault: too many cases" ) ; 
sel->ncase = i+1; 
cas = &sel->scase[i]; 
cas->index = index; 
cas->chan = nil; 
#line 609 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
cas->kind = CaseDefault; 
#line 611 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( debug ) 
runtime_printf ( "selectdefault s=%p index=%d\n" , 
sel , cas->index ) ; 
} 
#line 616 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void 
sellock ( Select *sel ) 
{ 
uint32 i; 
Hchan *c , *c0; 
#line 622 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
c = nil; 
for ( i=0; i<sel->ncase; i++ ) { 
c0 = sel->lockorder[i]; 
if ( c0 && c0 != c ) { 
c = sel->lockorder[i]; 
runtime_lock ( c ) ; 
} 
} 
} 
#line 632 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void 
selunlock ( Select *sel ) 
{ 
int32 i , n , r; 
Hchan *c; 
#line 646 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
n = ( int32 ) sel->ncase; 
r = 0; 
#line 649 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( n>0 && sel->lockorder[0] == nil ) 
r = 1; 
for ( i = n-1; i >= r; i-- ) { 
c = sel->lockorder[i]; 
if ( i>0 && sel->lockorder[i-1] == c ) 
continue; 
runtime_unlock ( c ) ; 
} 
} 
#line 659 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static bool 
selparkcommit ( G *gp , void *sel ) 
{ 
USED ( gp ) ; 
selunlock ( sel ) ; 
return true; 
} 
void runtime_block() __asm__ (GOSYM_PREFIX "runtime.block");
void runtime_block()
{
#line 667 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	runtime_park(nil, nil, "select (no cases)");	// forever
}

#line 671 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static int selectgo ( Select** ) ; 
int32 runtime_selectgo(Select* sel) __asm__ (GOSYM_PREFIX "runtime.selectgo");
int32 runtime_selectgo(Select* sel)
{
  int32 ret;
#line 675 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	return selectgo(&sel);
return ret;
}

#line 679 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static int 
selectgo ( Select **selp ) 
{ 
Select *sel; 
uint32 o , i , j , k , done; 
int64 t0; 
Scase *cas , *dfl; 
Hchan *c; 
SudoG *sg; 
G *gp; 
int index; 
G *g; 
#line 692 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
sel = *selp; 
if ( runtime_gcwaiting ( ) ) 
runtime_gosched ( ) ; 
#line 696 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( debug ) 
runtime_printf ( "select: sel=%p\n" , sel ) ; 
#line 699 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
g = runtime_g ( ) ; 
#line 701 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
t0 = 0; 
if ( runtime_blockprofilerate > 0 ) { 
t0 = runtime_cputicks ( ) ; 
for ( i=0; i<sel->ncase; i++ ) 
sel->scase[i].sg.releasetime = -1; 
} 
#line 717 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
for ( i=0; i<sel->ncase; i++ ) 
sel->pollorder[i] = i; 
for ( i=1; i<sel->ncase; i++ ) { 
o = sel->pollorder[i]; 
j = runtime_fastrand1 ( ) % ( i+1 ) ; 
sel->pollorder[i] = sel->pollorder[j]; 
sel->pollorder[j] = o; 
} 
#line 728 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
for ( i=0; i<sel->ncase; i++ ) { 
j = i; 
c = sel->scase[j].chan; 
while ( j > 0 && sel->lockorder[k= ( j-1 ) /2] < c ) { 
sel->lockorder[j] = sel->lockorder[k]; 
j = k; 
} 
sel->lockorder[j] = c; 
} 
for ( i=sel->ncase; i-->0; ) { 
c = sel->lockorder[i]; 
sel->lockorder[i] = sel->lockorder[0]; 
j = 0; 
for ( ;; ) { 
k = j*2+1; 
if ( k >= i ) 
break; 
if ( k+1 < i && sel->lockorder[k] < sel->lockorder[k+1] ) 
k++; 
if ( c < sel->lockorder[k] ) { 
sel->lockorder[j] = sel->lockorder[k]; 
j = k; 
continue; 
} 
break; 
} 
sel->lockorder[j] = c; 
} 
#line 763 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
sellock ( sel ) ; 
#line 765 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
loop: 
#line 767 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
dfl = nil; 
for ( i=0; i<sel->ncase; i++ ) { 
o = sel->pollorder[i]; 
cas = &sel->scase[o]; 
c = cas->chan; 
#line 773 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
switch ( cas->kind ) { 
case CaseRecv: 
if ( c->dataqsiz > 0 ) { 
if ( c->qcount > 0 ) 
goto asyncrecv; 
} else { 
sg = dequeue ( &c->sendq ) ; 
if ( sg != nil ) 
goto syncrecv; 
} 
if ( c->closed ) 
goto rclose; 
break; 
#line 787 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
case CaseSend: 
if ( raceenabled ) 
runtime_racereadpc ( c , runtime_selectgo , chansend ) ; 
if ( c->closed ) 
goto sclose; 
if ( c->dataqsiz > 0 ) { 
if ( c->qcount < c->dataqsiz ) 
goto asyncsend; 
} else { 
sg = dequeue ( &c->recvq ) ; 
if ( sg != nil ) 
goto syncsend; 
} 
break; 
#line 802 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
case CaseDefault: 
dfl = cas; 
break; 
} 
} 
#line 808 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( dfl != nil ) { 
selunlock ( sel ) ; 
cas = dfl; 
goto retc; 
} 
#line 816 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
done = 0; 
for ( i=0; i<sel->ncase; i++ ) { 
o = sel->pollorder[i]; 
cas = &sel->scase[o]; 
c = cas->chan; 
sg = &cas->sg; 
sg->g = g; 
sg->selectdone = &done; 
#line 825 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
switch ( cas->kind ) { 
case CaseRecv: 
enqueue ( &c->recvq , sg ) ; 
break; 
#line 830 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
case CaseSend: 
enqueue ( &c->sendq , sg ) ; 
break; 
} 
} 
#line 836 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
g->param = nil; 
runtime_park ( selparkcommit , sel , "select" ) ; 
#line 839 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
sellock ( sel ) ; 
sg = g->param; 
#line 844 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
for ( i=0; i<sel->ncase; i++ ) { 
cas = &sel->scase[i]; 
if ( cas != ( Scase* ) sg ) { 
c = cas->chan; 
if ( cas->kind == CaseSend ) 
dequeueg ( &c->sendq ) ; 
else 
dequeueg ( &c->recvq ) ; 
} 
} 
#line 855 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( sg == nil ) 
goto loop; 
#line 858 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
cas = ( Scase* ) sg; 
c = cas->chan; 
#line 861 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( c->dataqsiz > 0 ) 
runtime_throw ( "selectgo: shouldn't happen" ) ; 
#line 864 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( debug ) 
runtime_printf ( "wait-return: sel=%p c=%p cas=%p kind=%d\n" , 
sel , c , cas , cas->kind ) ; 
#line 868 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( cas->kind == CaseRecv ) { 
if ( cas->receivedp != nil ) 
*cas->receivedp = true; 
} 
#line 873 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( raceenabled ) { 
if ( cas->kind == CaseRecv && cas->sg.elem != nil ) 
runtime_racewriteobjectpc ( cas->sg.elem , c->elemtype , selectgo , chanrecv ) ; 
else if ( cas->kind == CaseSend ) 
runtime_racereadobjectpc ( cas->sg.elem , c->elemtype , selectgo , chansend ) ; 
} 
#line 880 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
selunlock ( sel ) ; 
goto retc; 
#line 883 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
asyncrecv: 
#line 885 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( raceenabled ) { 
if ( cas->sg.elem != nil ) 
runtime_racewriteobjectpc ( cas->sg.elem , c->elemtype , selectgo , chanrecv ) ; 
runtime_raceacquire ( chanbuf ( c , c->recvx ) ) ; 
} 
if ( cas->receivedp != nil ) 
*cas->receivedp = true; 
if ( cas->sg.elem != nil ) 
runtime_memmove ( cas->sg.elem , chanbuf ( c , c->recvx ) , c->elemsize ) ; 
runtime_memclr ( chanbuf ( c , c->recvx ) , c->elemsize ) ; 
if ( ++c->recvx == c->dataqsiz ) 
c->recvx = 0; 
c->qcount--; 
sg = dequeue ( &c->sendq ) ; 
if ( sg != nil ) { 
gp = sg->g; 
selunlock ( sel ) ; 
if ( sg->releasetime ) 
sg->releasetime = runtime_cputicks ( ) ; 
runtime_ready ( gp ) ; 
} else { 
selunlock ( sel ) ; 
} 
goto retc; 
#line 910 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
asyncsend: 
#line 912 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( raceenabled ) { 
runtime_racerelease ( chanbuf ( c , c->sendx ) ) ; 
runtime_racereadobjectpc ( cas->sg.elem , c->elemtype , selectgo , chansend ) ; 
} 
runtime_memmove ( chanbuf ( c , c->sendx ) , cas->sg.elem , c->elemsize ) ; 
if ( ++c->sendx == c->dataqsiz ) 
c->sendx = 0; 
c->qcount++; 
sg = dequeue ( &c->recvq ) ; 
if ( sg != nil ) { 
gp = sg->g; 
selunlock ( sel ) ; 
if ( sg->releasetime ) 
sg->releasetime = runtime_cputicks ( ) ; 
runtime_ready ( gp ) ; 
} else { 
selunlock ( sel ) ; 
} 
goto retc; 
#line 932 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
syncrecv: 
#line 934 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( raceenabled ) { 
if ( cas->sg.elem != nil ) 
runtime_racewriteobjectpc ( cas->sg.elem , c->elemtype , selectgo , chanrecv ) ; 
racesync ( c , sg ) ; 
} 
selunlock ( sel ) ; 
if ( debug ) 
runtime_printf ( "syncrecv: sel=%p c=%p o=%d\n" , sel , c , o ) ; 
if ( cas->receivedp != nil ) 
*cas->receivedp = true; 
if ( cas->sg.elem != nil ) 
runtime_memmove ( cas->sg.elem , sg->elem , c->elemsize ) ; 
gp = sg->g; 
gp->param = sg; 
if ( sg->releasetime ) 
sg->releasetime = runtime_cputicks ( ) ; 
runtime_ready ( gp ) ; 
goto retc; 
#line 953 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
rclose: 
#line 955 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
selunlock ( sel ) ; 
if ( cas->receivedp != nil ) 
*cas->receivedp = false; 
if ( cas->sg.elem != nil ) 
runtime_memclr ( cas->sg.elem , c->elemsize ) ; 
if ( raceenabled ) 
runtime_raceacquire ( c ) ; 
goto retc; 
#line 964 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
syncsend: 
#line 966 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( raceenabled ) { 
runtime_racereadobjectpc ( cas->sg.elem , c->elemtype , selectgo , chansend ) ; 
racesync ( c , sg ) ; 
} 
selunlock ( sel ) ; 
if ( debug ) 
runtime_printf ( "syncsend: sel=%p c=%p o=%d\n" , sel , c , o ) ; 
if ( sg->elem != nil ) 
runtime_memmove ( sg->elem , cas->sg.elem , c->elemsize ) ; 
gp = sg->g; 
gp->param = sg; 
if ( sg->releasetime ) 
sg->releasetime = runtime_cputicks ( ) ; 
runtime_ready ( gp ) ; 
#line 981 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
retc: 
#line 983 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
index = cas->index; 
if ( cas->sg.releasetime > 0 ) 
runtime_blockevent ( cas->sg.releasetime - t0 , 2 ) ; 
runtime_free ( sel ) ; 
return index; 
#line 989 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
sclose: 
#line 991 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
selunlock ( sel ) ; 
runtime_panicstring ( "send on closed channel" ) ; 
return 0; 
} 
#line 997 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
typedef struct runtimeSelect runtimeSelect; 
struct runtimeSelect 
{ 
uintptr dir; 
ChanType *typ; 
Hchan *ch; 
byte *val; 
} ; 
#line 1007 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
enum SelectDir { 
SelectSend = 1 , 
SelectRecv , 
SelectDefault , 
} ; 
struct reflect_rselect_ret {
  intgo chosen;
  bool recvOK;
};
struct reflect_rselect_ret reflect_rselect(Slice cases) __asm__ (GOSYM_PREFIX "reflect.rselect");
struct reflect_rselect_ret reflect_rselect(Slice cases)
{
  intgo chosen;
  bool recvOK;
#line 1013 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	int32 i;
	Select *sel;
	runtimeSelect* rcase, *rc;

	chosen = -1;
	recvOK = false;

	rcase = (runtimeSelect*)cases.__values;

	sel = newselect(cases.__count);
	for(i=0; i<cases.__count; i++) {
		rc = &rcase[i];
		switch(rc->dir) {
		case SelectDefault:
			selectdefault(sel, i);
			break;
		case SelectSend:
			if(rc->ch == nil)
				break;
			selectsend(sel, rc->ch, i, rc->val);
			break;
		case SelectRecv:
			if(rc->ch == nil)
				break;
			selectrecv(sel, rc->ch, i, rc->val, &recvOK);
			break;
		}
	}

	chosen = (intgo)(uintptr)selectgo(&sel);
  {
    struct reflect_rselect_ret __ret;
    __ret.chosen = chosen;
    __ret.recvOK = recvOK;
    return __ret;
  }
}

#line 1046 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void closechan ( Hchan *c , void *pc ) ; 
void runtime_closechan(Hchan* c) __asm__ (GOSYM_PREFIX "runtime.closechan");
void runtime_closechan(Hchan* c)
{
#line 1048 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	closechan(c, runtime_getcallerpc(&c));
}
void reflect_chanclose(Hchan* c) __asm__ (GOSYM_PREFIX "reflect.chanclose");
void reflect_chanclose(Hchan* c)
{
#line 1052 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	closechan(c, runtime_getcallerpc(&c));
}

#line 1056 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void 
closechan ( Hchan *c , void *pc ) 
{ 
SudoG *sg; 
G* gp; 
#line 1062 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( c == nil ) 
runtime_panicstring ( "close of nil channel" ) ; 
#line 1065 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( runtime_gcwaiting ( ) ) 
runtime_gosched ( ) ; 
#line 1068 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
runtime_lock ( c ) ; 
if ( c->closed ) { 
runtime_unlock ( c ) ; 
runtime_panicstring ( "close of closed channel" ) ; 
} 
#line 1074 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( raceenabled ) { 
runtime_racewritepc ( c , pc , runtime_closechan ) ; 
runtime_racerelease ( c ) ; 
} 
#line 1079 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
c->closed = true; 
#line 1082 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
for ( ;; ) { 
sg = dequeue ( &c->recvq ) ; 
if ( sg == nil ) 
break; 
gp = sg->g; 
gp->param = nil; 
if ( sg->releasetime ) 
sg->releasetime = runtime_cputicks ( ) ; 
runtime_ready ( gp ) ; 
} 
#line 1094 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
for ( ;; ) { 
sg = dequeue ( &c->sendq ) ; 
if ( sg == nil ) 
break; 
gp = sg->g; 
gp->param = nil; 
if ( sg->releasetime ) 
sg->releasetime = runtime_cputicks ( ) ; 
runtime_ready ( gp ) ; 
} 
#line 1105 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
runtime_unlock ( c ) ; 
} 
#line 1108 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
void 
__go_builtin_close ( Hchan *c ) 
{ 
runtime_closechan ( c ) ; 
} 
intgo reflect_chanlen(Hchan* c) __asm__ (GOSYM_PREFIX "reflect.chanlen");
intgo reflect_chanlen(Hchan* c)
{
  intgo len;
#line 1114 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	if(c == nil)
		len = 0;
	else
		len = c->qcount;
return len;
}

#line 1121 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
intgo 
__go_chan_len ( Hchan *c ) 
{ 
return reflect_chanlen ( c ) ; 
} 
intgo reflect_chancap(Hchan* c) __asm__ (GOSYM_PREFIX "reflect.chancap");
intgo reflect_chancap(Hchan* c)
{
  intgo cap;
#line 1127 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"

	if(c == nil)
		cap = 0;
	else
		cap = c->dataqsiz;
return cap;
}

#line 1134 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
intgo 
__go_chan_cap ( Hchan *c ) 
{ 
return reflect_chancap ( c ) ; 
} 
#line 1140 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static SudoG* 
dequeue ( WaitQ *q ) 
{ 
SudoG *sgp; 
#line 1145 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
loop: 
sgp = q->first; 
if ( sgp == nil ) 
return nil; 
q->first = sgp->link; 
#line 1152 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( sgp->selectdone != nil ) { 
#line 1154 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
if ( *sgp->selectdone != 0 || !runtime_cas ( sgp->selectdone , 0 , 1 ) ) 
goto loop; 
} 
#line 1158 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
return sgp; 
} 
#line 1161 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void 
dequeueg ( WaitQ *q ) 
{ 
SudoG **l , *sgp , *prevsgp; 
G *g; 
#line 1167 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
g = runtime_g ( ) ; 
prevsgp = nil; 
for ( l=&q->first; ( sgp=*l ) != nil; l=&sgp->link , prevsgp=sgp ) { 
if ( sgp->g == g ) { 
*l = sgp->link; 
if ( q->last == sgp ) 
q->last = prevsgp; 
break; 
} 
} 
} 
#line 1179 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void 
enqueue ( WaitQ *q , SudoG *sgp ) 
{ 
sgp->link = nil; 
if ( q->first == nil ) { 
q->first = sgp; 
q->last = sgp; 
return; 
} 
q->last->link = sgp; 
q->last = sgp; 
} 
#line 1192 "../../../trunk/libgo/runtime/../../../trunk/libgo/runtime/chan.goc"
static void 
racesync ( Hchan *c , SudoG *sg ) 
{ 
runtime_racerelease ( chanbuf ( c , 0 ) ) ; 
runtime_raceacquireg ( sg->g , chanbuf ( c , 0 ) ) ; 
runtime_racereleaseg ( sg->g , chanbuf ( c , 0 ) ) ; 
runtime_raceacquire ( chanbuf ( c , 0 ) ) ; 
} 