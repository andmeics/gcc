/* This includes all of the vector modes that are recognized by
   c_common_type_for_mode, grouped by base mode.  */

typedef int __attribute__((mode(QI))) qi;
typedef int __attribute__((mode(V8QI))) v8qi;
typedef int __attribute__((mode(V16QI))) v16qi;

typedef union U8QI { v8qi v; qi a[8]; } u8qi;
typedef union U16QI { v16qi v; qi a[16]; } u16qi;

typedef int __attribute__((mode(HI))) hi;
typedef int __attribute__((mode(V2HI))) v2hi;
typedef int __attribute__((mode(V4HI))) v4hi;
typedef int __attribute__((mode(V8HI))) v8hi;

typedef union U2HI { v2hi v; hi a[2]; } u2hi;
typedef union U4HI { v4hi v; hi a[4]; } u4hi;
typedef union U8HI { v8hi v; hi a[8]; } u8hi;

typedef int __attribute__((mode(SI))) si;
typedef int __attribute__((mode(V2SI))) v2si;
typedef int __attribute__((mode(V4SI))) v4si;

typedef union U2SI { v2si v; si a[2]; } u2si;
typedef union U4SI { v4si v; si a[4]; } u4si;

typedef int __attribute__((mode(DI))) di;
typedef int __attribute__((mode(V1DI))) v1di;
typedef int __attribute__((mode(V2DI))) v2di;

typedef union U1DI { v1di v; di a[1]; } u1di;
typedef union U2DI { v2di v; di a[2]; } u2di;

typedef float __attribute__((mode(SF))) sf;
typedef float __attribute__((mode(V2SF))) v2sf;
typedef float __attribute__((mode(V4SF))) v4sf;
typedef float __attribute__((mode(V16SF))) v16sf;

typedef union U2SF { v2sf v; sf a[2]; } u2sf;
typedef union U4SF { v4sf v; sf a[4]; } u4sf;
typedef union U16SF { v16sf v; sf a[16]; } u16sf;

typedef float __attribute__((mode(DF))) df;
typedef float __attribute__((mode(V2DF))) v2df;

typedef union U2DF { v2df v; df a[2]; } u2df;
