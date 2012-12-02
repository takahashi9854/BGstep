#include "gmp.h"
#include "gmpxx.h"
#include "Point.h"
#include "util.h"
#include <iostream>
#include <cmath>

int main(int argc, char *argvp[]){

  // y^2 = x^3 + ax^2 + bx + c
  // y^2 = x^3 + 2
  Point::a=0;
  Point::b=0;
  Point::c=2;

  long long q = 7; // F_q
  long long m = sqrt(sqrt(q));
  Point store[m+1];
  
  Point P(3,1,1);
  Point Q(3,1,1);
  Point R;
  Point S;

  R = P.ECpower(q+1,q);

  for(int i=0;i<=m;i++) store[i] = P.ECpower(i,q);

  
  
  return 0;
}
