#include "gmp.h"
#include "gmpxx.h"
#include <string>

#define POINT_H

class Point{
public:
  long long x;
  long long y;
  long long z;

  static long long a,b,c;

  Point();
  Point(long long X,long long Y,long long Z);
  // Point(std::string X,std::string Y,std::string Z);
  // Some utility functions.
  // void init();
  // void set(long long x,long long y,long long z);
  
  void ECadd(Point P,Point Q,long long m);
  // void ECadd2(Point P,Point Q,mpq_class m);

  static void check(Point P,Point Q);
  
  Point reflect();  

  // operator overload
  // Point operator+(const Point& obj);
  // Point operator-(const Point& obj);
  // I don't know hot to define this operator.
  // Does any good idea exist?
  // Point operator=(const Point& obj);
  // Point operator-=(Point obj);
    
  void copy(Point P);
  void show();
  

};

