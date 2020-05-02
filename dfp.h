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
* Nabla is vector that contains value of derivative in particular point
*/
template <typename T>
std:vector<T> nabla(std::vector<T>& X, std::vector<T> (*derivative)(std::vector<T>&)) {
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
