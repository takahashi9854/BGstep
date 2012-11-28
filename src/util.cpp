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

void xeuclid(const int a,const int b,int *u,int *v,int *g){
  int x=0,y=b; *u=1,*g=a;
  int s,t,q;
  while(y!=0){
    t=*g%y;
    q=(*g-t)/y;
    s=*u - q * x;
    *u = x; *g = y;
    x = s; y = t;
  }
  *v = (*g - a * (*u))/b;
}
