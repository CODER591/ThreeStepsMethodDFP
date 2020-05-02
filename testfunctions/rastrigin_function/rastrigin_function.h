
#include "common/common.h"
#include <vector>
#include <math.h>

LONG rastrigin_function(std::vector<T> & X) {
  return rastrigin_function_internal(std::vector<T> & X,10);
}



LONG rastrigin_function_internal(std::vector<T> & X,LONG A) {
  LONG result = 0;
  for(int i=0;i<X.size();i++) {
      result += X[i]*X[i] - A*cos(2*PI*X[i]);
  }
  return A*X.size() + result;
}
