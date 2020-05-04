
#include <vector>
#include <iostream>
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
          result[i] += Hess[i][j]*Y[j];
      }
    }
    return result;
}

template <typename T>
void MatrOut(std::vector<std::vector<T> > &matr) {
  for(size_t i = 0; i < matr.size();i++) {
    for(size_t j = 0; j < matr[i].size();j++) {
       std::cout << matr[i][j]<<" ";
    }
    std::cout<<std::endl;
  }

}


template <typename T>
std::vector<std::vector<T> > invertion_1(std::vector<std::vector<T> >&A) {
  std::vector<std::vector<T> > E(A.size());
  for (size_t i = 0 ; i < A.size() ; i++ ){
    E[i].resize(A.size());
  }
  int N = A.size();
  T temp;
  for (int i = 0; i < N; i++)
       for (int j = 0; j < N; j++)
       {
           E[i][j] = 0.0;

           if (i == j)
               E[i][j] = 1.0;
       }

   for (int k = 0; k < N; k++)
   {
       temp = A[k][k];

       for (int j = 0; j < N; j++)
       {
           A[k][j] /= temp;
           E[k][j] /= temp;
       }

       for (int i = k + 1; i < N; i++)
       {
           temp = A[i][k];

           for (int j = 0; j < N; j++)
           {
               A[i][j] -= A[k][j] * temp;
               E[i][j] -= E[k][j] * temp;
           }
       }
   }

   for (int k = N - 1; k > 0; k--)
   {
       for (int i = k - 1; i >= 0; i--)
       {
           temp = A[i][k];

           for (int j = 0; j < N; j++)
           {
               A[i][j] -= A[k][j] * temp;
               E[i][j] -= E[k][j] * temp;
           }
       }
   }

   for (int i = 0; i < N; i++)
       for (int j = 0; j < N; j++)
           A[i][j] = E[i][j];
      return A;
}
