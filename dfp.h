/*
This file is created for contatining DFP method implementation
Davis-Flatcher-Powell
Presentation with theoretical desctiption of this method is in repository files
*/

#include <vector>

template<typename T>
std::vector<T> vectors_difference(std::vector<T>& X, std::vector<T>& Y) {
  std::vector<T> result_v(X.size());
  for(size_t i = 0;i < X;i++) {
    result_v[i] = X[i] - Y[i];
  }
  return result_v;
}

/* Nabla is vector that holds derivatives by each variable accordingly
* Example:
*  x_0 = (x1, x2, x3, ..., xn)
*  f(x_0)  = value;
* Nabla f == Nabla(f) = ( df/x1, df/dx2, df/dx2, ..., df/dxn)
*
*/

template <typename T>
void nabla(){

}
