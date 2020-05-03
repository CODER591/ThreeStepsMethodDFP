
#include <vector>

template <typename T>
std::vector<std::vector<T> > mult_matrix_on_scalar(std::vector<std::vector<T> >& matr,T scalar) {
  std::vector<std::vector<T> > result(matr.size());
  for (size_t i = 0 ; i < matr.size() ; i++ ){
    result[i].resize(matr.size());
  }
  for(size_t i=0; i < matr.size(); i++) {
    for(size_t j = 0; j < matr[i].size(); j++) {
      result[i][j]=matr[i][j]*scalar;
    }
  }
  return result;
}


template <typename T>
std::vector<std::vector<T> > sum_matrices (std::vector<std::vector<T> >&X,std::vector<std::vector<T> >&Y) {
  std::vector<std::vector<T> > matrix(X.size());
  for (size_t i = 0 ; i < X.size() ; i++ ){
    matrix[i].resize(X.size());
  }
  for (int i = 0; i < X.size(); ++i){
      for (int j = 0; j < X[i].size(); ++j){
          matrix[i][j] = X[i][j] + Y[i][j];
      }
  }
  return matrix;
}
template <typename T>
std::vector<std::vector<T> > vector_multipl_T(std::vector<T> &X, std::vector<T> &Y){
    std::vector<std::vector<T> > M(X.size(), std::vector<T>(X.size()));
    for (int i = 0; i < X.size(); ++i){
        for (int j = 0; j < X.size(); ++j){
            M[i][j] = X[i] * Y[j];
        }
    }
    return M;
}


template <typename T>
std::vector<T> matr_vec_multiply(std::vector<std::vector<T> > &Hess, std::vector<T> &Y) {
  std::vector<T> result(Y.size());
    for(size_t i = 0; i < Hess.size();i++) {
      for(size_t j = 0; j < Hess[i].size();j++) {
          result[i] += Hess[i][j]*Y[i];
      }
    }
    return result;
}
