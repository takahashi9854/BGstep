#include "util.h"

int gcd(int a,int b){
  int r;
  while(b>0){
    r=a%b;
    a=b;
    b=r;
  }

  return a;
}
