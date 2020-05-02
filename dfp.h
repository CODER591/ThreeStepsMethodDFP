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
     /* Step 1
      * 1. calculate g_k
      * 2. calculate -H_k
      * 3. calculate d_k = -H_(k) * g_(k)
      */

     std::vector<T> g_k = nabla(X,rosenbrock_deriv); // check
     hessian_matr = mult_matrix_on_scalar(hessian_matr,(T)-1); //check
     std::vector<T> d_k = matr_vec_multiply(hessian_matr, g_k); //check
     /* Step 2
      * 1. calculate x_k+1
      * 2. calculate p_k
      * 3. calculate g_(k+1)
      */
      std::vector<T> alpha_d_k = scalar_mult_vec(d_k,alpha); //check
      std::vector<T> X_k_next = vectors_sum(X,alpha_d_k); //check
      std::vector<T> p_k = alpha_d_k;
      std::vector<T> g_k_next =nabla(X_k_next,rosenbrock_deriv); 

      /* Step 3
       * 1. calculate q_k
       * 2. Main hessian formula
       * ....
       */



}
