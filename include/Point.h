#include "gmp.h"
#include "gmpxx.h"
#include <string>

#define POINT_H

class Point{
public:
  // long long x;
  // long long y;
  // long long z;
  mpz_class x;
  mpz_class y;
  mpz_class z;

  // static long long a,b,c;
  static mpz_class a,b,c;

  Point();
  // Point(long long X,long long Y,long long Z);
  Point(mpz_class X, mpz_class Y, mpz_class Z);
  // Point(std::string X,std::string Y,std::string Z);
  // Some utility functions.
  void init();
  // void set(long long x,long long y,long long z);
  
  // void ECadd(Point P,Point Q,long long m);
  void ECadd(Point P,Point Q,mpz_class m);
  // void ECadd2(Point P,Point Q,mpq_class m);

  // Point ECpower(long long n,long long m);
  Point ECpower(mpz_class n,mpz_class m);
  
  static void check(Point P,Point Q);
  
  Point reflect();  

  // operator overload
  // Point operator+(const Point& obj);
  // Point operator-(const Point& obj);
  // I don't know hot to define this operator.
  // Does any good idea exist?
  Point operator=(const Point& obj);
  int operator==(const Point& obj);
  // Point operator-=(Point obj);
    
  void copy(Point P);
  void show();
  

};

