/* Test __GCC_IEC_559 and __GCC_IEC_559_COMPLEX macros values.  */
/* { dg-do preprocess } */
/* { dg-options "" } */

#ifndef __GCC_IEC_559
# error "__GCC_IEC_559 not defined"
#endif
#ifndef __GCC_IEC_559_COMPLEX
# error "__GCC_IEC_559_COMPLEX not defined"
#endif
#if __GCC_IEC_559_COMPLEX > __GCC_IEC_559
# error "__GCC_IEC_559_COMPLEX > __GCC_IEC_559"
#endif
#if __GCC_IEC_559_COMPLEX < 0
# error "__GCC_IEC_559_COMPLEX < 0"
#endif
