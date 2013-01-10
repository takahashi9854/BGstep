#include "gmp.h"
#include "gmpxx.h"
#include "Point.h"
#include "util.h"
#include <iostream>
#include <cmath>


int main(int argc, char *argvp[]){

  // y^2 = x^3 + ax^2 + bx + c
  // y^2 = x^3 - 10x + 21 over F_557
  Point::a=0;
  Point::b=10;
  Point::c=-21;

  int i,j,k;

  // long long M;
  mpz_class M;
  // long long q = 557; // F_q
  mpz_class q = 557;
  // long long m = floor(sqrt(sqrt(q))) + 1; // calculate the forth root of q.
  mpz_class m = sqrt(sqrt(q)) + 1;
  std::cout << "m = "  << m << std::endl;


  // here is the step 1.
  Point P(2,3,1); // want to find the order of this point.
  std::cout << "q+1 = " << q+1 << std::endl;
  Point Q = P.ECpower(q+1,q); // calculate Q = (q+1)P.
  Point R;
  std::cout << "Q" << std::endl;
  Q.show();
  Q = Point();
  Q.show();
  for(i=1;i<=1;i++){
    R.ECadd(P,P,q);
    std::cout << "i = " << i << std::endl;
    R.show();
    Q = R;
  }

  Q = Point(58,164,1);
  R.ECadd(P,Q,q);
  R.show();
  
  // here is the step 2.
  unsigned long size = mpz_class::get_ui(m);
  Point *store = new Point[size+1]; // default constructor.

  /*
  for(i=0;i<=m;i++){
    store[i] = P.ECpower(i,q); // store jP for j=0,1,2,...,m.
    // std::cout << "i = " << i << std::endl;
    // P.ECpower(i,q).show();
  }

  Point _2mP = P.ECpower(2*m,q);
  // std::cout << "_2mP" << std::endl;
  // _2mP.show();
  Point R; // store Q + k(2m)p. that mean, Q + k*(_2mP);
  R = _2mP.ECpower(k,q);
  // std::cout << "R" << std::endl;
  // R.show();
    
  Point result;

  // show _2mP.
  // std::cout << "coordinates of _2mP." << std::endl;
  // _2mP.show();
 
  // show all points in store[]
  std::cout << "all points in store[]" << std::endl;
  for(int i=0;i<=m;i++)
    store[i].show();

  // start checking points are equall to R.
  // here is the step 3.
  k = 0;
  R.ECadd(R,_2mP.ECpower(k,q),q);
  // check coordinates of R and calculate 
  // std::cout << "R" << std::endl;
  // R.show();
  
  // check where it is.
  // std::cout << "before while" << std::endl;
  while(k<=m){
    // std::cout << "store[" << k << "] = " << store[k].x << std::endl;
    // std::cout << "R.x" << R.x << std::endl;
    if(store[k].x == R.x && store[k].y == R.y){
      // show success.
      std::cout << "find point." << std::endl;
      break;
    }
    k++;
    R.ECadd(R,_2mP,q);
  }
  result = store[k];
  if(result == R){
    M = q + 1 + 2*m*k + 1;
  }else{
    M = q + 1 + 2*m*k - 1;
  }
  std::cout << "k = " << k << std::endl;
  std::cout << "m = " << m << std::endl;
  std::cout << "q = " << q << std::endl;
  std::cout << M << std::endl;
  
    

  */
  delete [] store; // destoroy array.
  return 0;
}
