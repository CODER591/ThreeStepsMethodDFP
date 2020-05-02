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

#else

typedef long double LONG;


#endif

/* Not quite remember regarding reason of redefinition of this function */
//delete me pretendent
LONG Pow(LONG a, int powr)
{
  LONG tmp = 1;
  for (int i = 0; i < powr; i++)
  {
    tmp *= a;
  }
  return tmp;
}




#endif /* COMMON_H */
