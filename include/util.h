#define UTIL_H

#include <stdio.h>

#include "gmp.h"
#include "gmpxx.h"

// GCD
int gcd(int a,int b);
// Extended Euclid's Algorithm with GCD.
void xeuclid(const int a,const int b,int *u,int *v,int *g);
// Extended Euclid's Algorithm without GCD.
void xeuclid(const int a,const int b,int *u,int *v);
// Calculate the inverse in F_m.
// If we get -1, there doesn't exist inverse in F_m.
long long inv_mod(long long a,long long m);
