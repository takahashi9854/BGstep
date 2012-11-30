#include "gmp.h"
#include "gmpxx.h"
#include "Point.h"
#include "util.h"
#include <iostream>

int main(int argc, char *argvp[]){

  // y^2 = x^3 + ax^2 + bx + c
  Point::a=0;
  Point::b=0;
  Point::c=2;

  Point P(3,1,1);
  Point Q(3,1,1);
  Point R;
  Point S;
  for(int i=1;i<=9;i++){
    P.ECpower(i,7);
    std::cout << "i = " << i << std::endl;
    P.show();
    P.copy(Q);
  }
  return 0;
}
