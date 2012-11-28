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

// Extended Euclid's Algorithm with GCD.
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

// Extended Euclid's Algorithm without GCD.
void xeuclid(const int a,const int b,int *u,int *v){
  int x=0,y=b,g=a; *u=1;
  int s,t,q;
  while(y!=0){
    t=g%y;
    q=(g-t)/y;
    s=*u - q * x;
    *u = x; g = y;
    x = s; y = t;
  }
  *v = (g - a * (*u))/b;
}

// Inverse in mod m.
// If we get -1, there doesn't exist inverse in F_m.
int inv_mod(int a,int m){
  int x=0,y=m;
  int u=1,v,g=a;
  int s,t,q;
  while(y!=0){
    t=g%y;
    q=(g-t)/y;
    s=u - q*x;
    u = x; g = y;
    x = s; y = t;
  }
  while(u<0) u+=m;
  if(u==1) return -1;
  else return u;
}
