#include "gmp.h"
#include "gmpxx.h"
#include <string>

#define POINT_H

class Point{
public:
  mpq_class x;
  mpq_class y;
  mpq_class z;

  static mpq_class a,b,c;

  Point();
  Point(mpq_class X,mpq_class Y,mpq_class Z);
  Point(std::string X,std::string Y,std::string Z);
  // Some utility functions.
  void init();
  void set(mpq_class x,mpq_class y,mpq_class z);
  
  void ECadd(Point P,Point Q);

  static void check(Point P,Point Q);
  
  Point reflect();  

  // operator overload
  Point operator+(const Point& obj);
  Point operator-(const Point& obj);
  // I don't know hot to define this operator.
  // Does any good idea exist?
  // Point operator=(const Point& obj);
  // Point operator-=(Point obj);
    
  void copy(Point P);
  void show();
  

};

