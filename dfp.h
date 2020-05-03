/*
This file is created for contatining DFP method implementation
Davis-Flatcher-Powell
Presentation with theoretical desctiption of this method is in repository files
*/
#include <vector>
#include <algorithm>
#include "testfunctions/common/common.h"
#include "testfunctions/rosenbrock_function/rosenbrock_test_func.h"

template <typename T>
std::vector<std::vector<T> > invert_matrix(std::vector<std::vector<T> > &X) {
  int i,j,k;
  T a,ratio;
  std::vector<std::vector<T> > matrix(X.size());
  for (size_t i = 0 ; i < X.size() ; i++ ){
    matrix[i].resize(X.size());
  }

  int n = X.size();
  for(i = 0; i < n; i++){
        for(j = n; j < 2*n; j++){
            if(i==(j-n))
                matrix[i][j] = 1.0;
            else
                matrix[i][j] = 0.0;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i!=j){
                ratio = matrix[j][i]/matrix[i][i];
                for(k = 0; k < 2*n; k++){
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }
    for(i = 0; i < n; i++){
        a = matrix[i][i];
        for(j = 0; j < 2*n; j++){
            matrix[i][j] /= a;
        }
    }
    return matrix;
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

template <typename T>
std::vector<T> scalar_mult_vec(std::vector<T> &X,T scalar) {
  std::vector<T> result(X.size());
  for(size_t i = 0; i < X.size();i++) {
    result[i] = X[i] * scalar;
  }
  return result;
}

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

/* Nabla is vector that holds derivatives by each variable accordingly
* Example:
*  x_0 = (x1, x2, x3, ..., xn)
*  f(x_0)  = value;
* Nabla f == Nabla(f) = ( df/x1, df/dx2, df/dx2, ..., df/dxn)
* Nabla is vector that contains value of derivative in particular point
*/
template <typename T>
std::vector<T> nabla(std::vector<T>& X, std::vector<T> (*derivative)(std::vector<T>&)) {
    return derivative(X);
}

/*
    Basic definitions
    g_(k+1) = nabla_f (x_(k+1)) g_(k) = nabla_f(x_(k))
    p_(k) = x_(k+1) - x_(k)
    q_(k) = g_(k+1) - g_(k) = nabla_f (x_(k+1)) - nabla_f(x_(k))
*/


/*
  H_0 = I = (1 0)
            (0 1)
  General plan
  1) d_k= -H_(k) * g_(k)
  2) alpha_k = argmin f(x_k + alpha*dk) ??
     x_k+1 = x_k + alpha_k * d_k
     p_k = x_k+1 - x_k = alpha * d_k
     g_(k+1) = nabla_f (x_(k+1))
  3) q_k = g_(k+1) - g_(k)
    Main hessian formula [rank 2 update]
  4) k = k+1 go to the 1 step


  Alpha coud be divided on some number, or  alpha == 1
  instead mysterious argmin
*/

template <typename T>
void DFP(std::vector<T> & X) {


     std::vector<T> Sup1;
     Sup1.push_back(1);
     Sup1.push_back(0);
     std::vector<T> Sup2;
     Sup2.push_back(0);
     Sup2.push_back(1);
     std::vector<std::vector<T> > hessian_matr; /* H_0 ==  I */
     hessian_matr.push_back(Sup1);
     hessian_matr.push_back(Sup2);

     std::vector<T> (*rosenbrock_deriv)(std::vector<T>&) = &RosenbrockFunc_derivative;
     T alpha = 1;
     int k = 0; /* Number of iteration*/

     /* Step 1
      * 1. calculate g_k
      * 2. calculate -H_k
      * 3. calculate d_k = -H_(k) * g_(k)
      */

     std::vector<T> g_k = nabla(X,rosenbrock_deriv); // check
     std::vector<std::vector<T> > minus_H_k = mult_matrix_on_scalar(hessian_matr,(T)-1); //check
     std::vector<T> d_k = matr_vec_multiply(minus_H_k, g_k); //check
     /* Step 2
      * 1. calculate x_k+1
      * 2. calculate p_k
      * 3. calculate g_(k+1)
      */
      std::vector<T> alpha_d_k = scalar_mult_vec(d_k,alpha);
      std::vector<T> X_k_next = vectors_sum(X,alpha_d_k);
      std::vector<T> p_k = alpha_d_k;
      std::vector<T> g_k_next = nabla(X_k_next,rosenbrock_deriv);

      /* Step 3
       * 1. calculate q_k
       * 2. Main hessian formula
       * ....
       */
       std::vector<T>q_k = vectors_difference(g_k_next,g_k);

       /* Main Hessian formula symmetric rank correction one (SR-1) */
       /* We know the first component H_k*/

       std::vector<T>H_kq_K = matr_vec_multiply(minus_H_k,q_k);
       /*Represents p_k - H_k*q_k*/
       std::vector<T>vec_hes_dif = vectors_sum(p_k,H_kq_K);
       T numerator = vector_scal_mult(vec_hes_dif,vec_hes_dif);


       /* Warning comment
       This step is need a lot of checkings, because of unrelyiable functions
       vector_multipl_T
       invert_matrix
      */
       std::vector<std::vector<T> > matrix_to_inverse = vector_multipl_T(q_k,H_kq_K);
       matrix_to_inverse = invert_matrix(matrix_to_inverse);
       std::vector<std::vector<T> > final_matr = mult_matrix_on_scalar(matrix_to_inverse,T(1)/numerator);

       std::vector<std::vector<T> > hessian_matr_next = sum_matrices(hessian_matr,final_matr);
       /* Denominator will be matrix */

       /*
        1) To implement Denominator we need to invert numerator and Denominator
        2) Multiply (q_k) and the vec_hes_dif -> get matrix
        3) Find inverted matrix
        4) And multiply it on the 1/numerator scalar
        6) Plus hessian
        7) Go to Step 4 in DFP algorithm
       */





}
