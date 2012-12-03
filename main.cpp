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

  int i,j,k;
  
  long long q = 7; // F_q
  long long m = sqrt(sqrt(q));
  Point *store = new Point[m+1]; // default constructor.

  Point P(3,1,1);
  Point R(3,2,1);
  Point rP;
  Point Q = P.ECpower(q+1,q);
  Point result,tmp,rtmp;
  for(i=0;i<=m;i++) store[i] = P.ECpower(i,q);
  k = m;
  while(k>=0){
    tmp.ECadd(Q,P.ECpower(k*2*m,q));
    rmpt = tmp.reflect();
    if(tmp == store[m]) break;
    if(rmpt == store[m]) break;
  }
      
    
  
  delete [] store;
  return 0;
}
