#ifndef JC_STD_TYPES_H
#define JC_STD_TYPES_H


#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))


/* ------  Numbers definition  ------ */
typedef unsigned char     n8;  /* %u or %c */
typedef unsigned short    n16; /* %u */
typedef unsigned int      n32; /* %u */
typedef unsigned long int n64; /* %lu */

typedef signed char     i8;  /* %d or %c */
typedef signed short    i16; /* %d */
typedef signed int      i32; /* %d */
typedef signed long int i64; /* %ld */


/* ------  Boolean definition  ------ */
enum bool_t {
	true  = (n8)(1 == 1),
	false = (n8)(1 != 1)
};
typedef enum bool_t bool; /* %d */


/* ------  Character definition  ------ */
typedef const char* const literal;
typedef unsigned char uchar; /* %c */
typedef signed char schar;   /* %c */


#endif /* JC_STD_TYPES_H */
