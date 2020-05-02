#ifndef ROSENBROCK_FUNC_H
#define ROSENBROCK_FUNC_H

#include "../common/common.h"
#include <vector>

template <typename T>
T RosenbrockFunc(std::vector<T> & X)
{
  T sum = 0;
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

template <typename T>
std::vector<T>  RosenbrockFunc_derivative(std::vector<T> &X) {
  std::vector<T> result(X.size());
  for (int i = 0; i < X.size(); i++) {
    if ((i + 1) % 2 == 0) {
      result[i] = T(100 * 2) * (X[i] - Pow(X[i - 1], 2));
    }
    if ((i + 1) % 2 != 0) {
      result[i] = T(-400) * X[i] * (X[i + 1] - Pow(X[i], 2)) - T(2) * (T(1) - X[i]);
    }
  }
  return result;
}

#endif /* ROSENROCK_FUNC_H */
