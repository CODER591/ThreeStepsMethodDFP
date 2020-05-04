
#include <vector>
#include <iostream>

template <typename T>
std::vector<T> scalar_mult_vec(std::vector<T> &X,T scalar) {
  std::vector<T> result(X.size());
  for(size_t i = 0; i < X.size();i++) {
    result[i] = X[i] * scalar;
  }
  return result;
}

template <typename T>
T vector_scal_mult(std::vector<T>& X, std::vector<T>& Y) {
  T result = 0;
  for(size_t i = 0;i < X.size(); i++) {
    result += X[i]*Y[i];
  }
  return result;
}

template <typename T>
std::vector<T> vectors_sum(std::vector<T>& X, std::vector<T>& Y) {
  std::vector<T> result_v(X.size());
  for(size_t i = 0;i < X.size(); i++) {
    result_v[i] = X[i] + Y[i];
  }
  return result_v;
}

template<typename T>
std::vector<T> vectors_difference(std::vector<T>& X, std::vector<T>& Y) {
  std::vector<T> result_v(X.size());
  for(size_t i = 0;i < X.size();i++) {
    result_v[i] = X[i] - Y[i];
  }
  return result_v;
}

template<typename T>
void VecOut(std::vector<T>& X) {
  for(size_t i = 0;i < X.size();i++) {
    std::cout<< X[i]<<std::endl;
  }

}
