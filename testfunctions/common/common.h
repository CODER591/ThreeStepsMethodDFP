#ifndef COMMON_H
#define COMMON_H

/*
* This file is created for holding:
* 1) additional type definitions
* 2) supply functions
*
*
*/

#define USE_PREPRO 1

#ifdef USE_PREPRO

#define LONG long double
//#define LONG double

#else

typedef long double LONG;


#endif

/* Not quite remember regarding reason of redefinition of this function */
//delete me pretendent
template <typename T>
T Pow(T a, int powr) {
  T tmp = 1;
  for (int i = 0; i < powr; i++) {
    tmp *= a;
  }
  return tmp;
}

template <typename T>
T Abs(T a) {
  return (a < 0)?T(-1)*a:a;
}


#endif /* COMMON_H */
