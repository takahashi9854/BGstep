#include "util.h"

#include "gmp.h"
#include "gmpxx.h"

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
//long long inv_mod(long long a,long long m){
mpz_class inv_mod(mpz_class a,mpz_class m){
  // long long x=0,y=m;
  // long long u=1,v,g=a;
  // long long s,t,q;
  mpz_class x=0,y=m;
  mpz_class u=1,g=a,v;
  mpz_class s,t,q;
  if(a == 1) exit(-1);
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
