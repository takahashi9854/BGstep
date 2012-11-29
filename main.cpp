#include "gmp.h"
#include "gmpxx.h"
#include "Point.h"
#include "util.h"

int main(int argc, char *argvp[]){

  // y^2 = x^3 + ax^2 + bx + c
  Point::a=0;
  Point::b=0;
  Point::c=2;

  Point P(3,1,1);
  Point Q(3,1,1);
  Point R;
  Point S;
  R.ECadd(P,Q,7);
  S.ECadd(R,Q,7);

  
  R.show();
  S.show();

  P = Point(3,1,1);
  P.ECpower(3,7);
  R.show();

  return 0;
}
