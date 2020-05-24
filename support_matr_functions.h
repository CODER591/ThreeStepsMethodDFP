
#include <vector>
#include <iostream>

#ifndef SUPORT_MATR_FUNC
#define SUPORT_MATR_FUNC

//avoid copy here
/*
std::vector<std::vector<T> > get_square_zeroed_matrix( unsigned int & size) {
   return std::vector<std::vector<T> > (size, std::vector<T>(size));
}
*/

template <typename T>
std::vector<std::vector<T> > mult_matrix_on_scalar(std::vector<std::vector<T> >& matr,T scalar) {
  std::vector<std::vector<T> > result(matr.size());
  for (size_t i = 0 ; i < matr.size() ; i++ ) {
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
std::vector<std::vector<T> > substract_matrices (std::vector<std::vector<T> >&X,std::vector<std::vector<T> >&Y) {
  std::vector<std::vector<T> > matrix(X.size());
  for (size_t i = 0 ; i < X.size() ; i++ ){
    matrix[i].resize(X.size());
  }
  for (int i = 0; i < X.size(); ++i){
      for (int j = 0; j < X[i].size(); ++j){
          matrix[i][j] = X[i][j] - Y[i][j];
      }
  }
  return matrix;
}

/*
  A - matrix
  b-  vector
  p - vector;
  A * b  = p */
template <typename T>
std::vector<T> matr_vec_multiply(std::vector<std::vector<T> > &Hess, std::vector<T> &Y) {
  std::vector<T> result(Y.size());
  for(size_t i = 0; i < Hess.size();i++) {
    for(size_t j = 0; j < Hess[i].size();j++) {
       result[i] += Hess[i][j] * Y[j];
    }
  }
  return result;
}
/*
  A - matrix
  b -  vector
  p - vector;
  b * A  = p */
template <typename T>
std::vector<T> vec_mult_matr(std::vector<T>& Y, std::vector<std::vector<T> >& Hess) {
  std::vector<T> result(Y.size());
  for(size_t i = 0; i < Hess.size(); i++) {
    for(size_t j = 0; j < Hess[i].size(); j++) {
       result[j] += Y[i] * Hess[i][j];
    }
  }
  return result;
}
/* Use where we need to A - 5
Which should be interpreted as A - (5 * I)
I is zeroed matrix with 1 on main diagonal
 */
template <typename T>
std::vector<std::vector<T> > matr_substract_number(std::vector<std::vector<T> > & Matr, T & number) {
  std::vector<std::vector<T> > result (Matr.size(), std::vector<T>(Matr.size()));
  for(size_t i = 0; i < result.size(); i++) {
       result[i][i] = number;
  }
  result = substract_matrices(Matr,result);
  return result;
}

template <typename T>
std::vector<std::vector<T> > matr_plus_number(std::vector<std::vector<T> > & Matr, T & number) {
  std::vector<std::vector<T> > result (Matr.size(), std::vector<T>(Matr.size()));
  for(size_t i = 0; i < result.size(); i++) {
       result[i][i] = number;
  }
  result = sum_matrices(Matr,result);
  return result;
}

template <typename T>
void MatrOut(std::vector<std::vector<T> > &matr) {
  for(size_t i = 0; i < matr.size();i++) {
    for(size_t j = 0; j < matr[i].size();j++) {
       std::cout << matr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


#endif /* SUPORT_MATR_FUNC*/
