

#include <iostream>
#include <vector>

#include "testfunctions/common/common.h"
#include "dfp.h"

int main() {

   std::vector<LONG> X;
   X.push_back(-1.2);//1
   X.push_back(1);//2
   DFP(X);

   return 0;
}
