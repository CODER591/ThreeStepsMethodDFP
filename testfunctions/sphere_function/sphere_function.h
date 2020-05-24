#ifndef SPHERE_FUNC_H
#define SPHERE_FUNC_H

#include <vector>
#include "../common/common.h"

template <typename T>
T SphereFunc(std::vector<T> & X) {
  T sum = 0;
  for(int i = 0; i < X.size(); i++) {
    sum += Pow(X[i], 2);
  }
  return sum;
}
template <typename T>
std::vector<T>  SphereFunc_derivative(std::vector<T>&X) {
  std::vector<T> result(X.size());
  for (int i = 0; i < X.size(); i++) {
    result[i] = T(2) * X[i];
  }
  return result;
}



#endif
