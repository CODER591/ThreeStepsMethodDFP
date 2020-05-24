/*
This file is created for contatining DFP method implementation
Davis-Flatcher-Powell
Presentation with theoretical desctiption of this method is in repository files
*/
#include <vector>
#include <algorithm>
#include "testfunctions/common/common.h"
#include "testfunctions/rosenbrock_function/rosenbrock_test_func.h"
#include "testfunctions/sphere_function/sphere_function.h"
#include "support_vec_functions.h"
#include "support_matr_functions.h"

/*
template <typename T>
 std::vector<std::vector<T> > SR_2_Hes_Update(std::vector<std::vector<T> > & hessian,
                                             std::vector<T>& p_k, std::vector<T>& q_k) {
   std::vector < std::vector<T> > updated_hessian = get_square_zeroed_matrix(hessian.size());
  T quantifyier1 = vector_scal_mult(p_k,p_k);
  T denomit1 =  vector_scal_mult(p_k,q_k);
  T first_division = quantifyier1 / denomit1;


//  T denomit2 = vector_mult_matr();
//  T second_division=

//plus hessian
   return updated_hessian;
 }*/

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

    // std::vector<T> (*rosenbrock_deriv)(std::vector<T>&) = &RosenbrockFunc_derivative;
    std::vector<T> (*rosenbrock_deriv)(std::vector<T>&) = &SphereFunc_derivative;
     T alpha = 0.1;
     T gam = 0.9999999;
     //T gam = 0.5;
     int k = 0; /* Number of iteration*/
     T eps = 0.001;
     /* Step 1
      * 1. calculate g_k
      * 2. calculate -H_k
      * 3. calculate d_k = -H_(k) * g_(k)
      */
for(int i=0;i<1;i++) {
//for(;;) {

     std::vector<T> g_k = nabla(X,rosenbrock_deriv); // check
     std::cout<<"g_k"<<std::endl;
     VecOut(g_k);
     std::cout<<"-------"<<std::endl;
     std::cout<<"hessian_matr"<<std::endl;
     MatrOut(hessian_matr);
     std::cout<<"-------"<<std::endl;
     std::vector<std::vector<T> > minus_H_k = mult_matrix_on_scalar(hessian_matr,T(-1)); //check
     std::cout<<"minus_H_k"<<std::endl;
     MatrOut(minus_H_k);
     std::cout<<"-------"<<std::endl;
     std::vector<T> d_k = matr_vec_multiply(minus_H_k, g_k); //check
     std::cout<<"d_k"<<std::endl;
     VecOut(d_k);
     std::cout<<"-------"<<std::endl;
     /* Step 2
      * 1. calculate x_k+1
      * 2. calculate p_k
      * 3. calculate g_(k+1)
      */
      std::vector<T> alpha_d_k = scalar_mult_vec(d_k,alpha);
      std::vector<T> X_k_next = vectors_sum(X,alpha_d_k);
      std::vector<T> p_k = alpha_d_k;
      std::vector<T> g_k_next = nabla(X_k_next,rosenbrock_deriv);
      std::cout<<"g_k_next"<<std::endl;
      VecOut(g_k_next);
      std::cout<<"-------"<<std::endl;
      /* Step 3
       * 1. calculate q_k
       * 2. Main hessian formula
       * ....
       */
       std::vector<T>q_k = vectors_difference(g_k_next,g_k);
       std::cout<<"q_k"<<std::endl;
       VecOut(q_k);
       std::cout<<"-------"<<std::endl;

       std::vector <std::vector<T> > hessian_matr_next;
      // = SR_2_Hes_Update(hessian_matr,p_k,q_k);

       VecOut(X);
       VecOut(X_k_next);
       std::cout<<"Ros vid X="<< RosenbrockFunc(X)<<std::endl;
       std::cout<<"Ros vid X_k_next="<< RosenbrockFunc(X_k_next)<<std::endl;

       /*if(RosenbrockFunc(X_k_next)-RosenbrockFunc(X)<eps){
         break;
       }*/
       X = X_k_next;
       hessian_matr = hessian_matr_next;
       alpha *= gam;
       k++;
       std::cout<<"--------------------END OF ITERAION---------"<<std::endl;

 }



}
