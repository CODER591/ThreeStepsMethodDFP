#ifndef ROSENBROCK_FUNC_H
#define ROSENROCK_FUNC_H

#include "common/common.h"


template <typename T>//+
LONG RosenbrockFunc(vector<T> & X)
{
  LONG sum = 0;
  /*if(X.size()==2)
  {
    return T(100) * (X[1] - Pow(X[0], 2))*(X[1] - Pow(X[0], 2)) + (1 - X[0])*(1 - X[0]);
  }*/
  for (int i = 1; i <= int(X.size() / 2); i++)
  {
    sum += (T(100) * Pow(X[2 * i - 1] - Pow(X[(2 * i) - 1 - 1], 2), 2)) + Pow(T(1) - X[(2 * i) - 1 - 1], 2);
  }
  return sum;
}

#endif
