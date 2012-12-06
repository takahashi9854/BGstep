#ifndef POINT_H
#include "Point.h"
#endif

#ifndef UTIL_H
#include "util.h"
#endif

#include "gmp.h"
#include "gmpxx.h"
#include <iostream>
#include <string>

extern const long long CONST = 13;
// y^2 = x^3 + ax^2 + bx + c
extern long long Point::a;
extern long long Point::b;
extern long long Point::c;


// Default Constructor.
Point::Point(): x(0),y(1),z(0) {
}

// Constructor using initialize variables which you want.
Point::Point(long long X,long long Y,long long Z): x(X),y(Y),z(Z){
}

// Point::Point(std::string X,std::string Y,std::string Z): x(X),y(Y),z(Z){
// }

void Point::copy(Point P){
  x = P.x;
  y = P.y;
  z = P.z;

  return;
}

// Showing coordinates of Point instance.
void Point::show(){
  std::cout << "(" << this->x << "," << this->y <<  "," << this->z << ")" << std::endl;
  // std::cout << "x=" << x << "\n" << "y=" << y << "\n" << "z=" << z <<"\n";
  // std::cout << "here is the end of showing coordinates of point.\n" << std::endl;
  return;
}

// Menber funciton to init instance.
// By default,initialized using original point.
void Point::init(){
  x=z=0;
  y=1;
}

// To reflect on x.
Point Point::reflect(){
  Point tmp(x,-1*y,z);
  return tmp;
}

// Additional two points.
// obj.canonicalize() is the function which reduction to this obj.
void Point::ECadd(Point P,Point Q,long long m){
  long long l;
  long long v;

  // for a unit element.
  if(P.z == 0){
    this->x=Q.x;this->y=Q.y;this->z=Q.z;
    return;
  }
  if(Q.z == 0){
    this->x=P.x;this->y=P.y;this->z=P.z;
    return;
  }
      
  if(P.x != Q.x && P.y != Q.y){
    l = ((P.y - Q.y)%m)*(inv_mod(P.x - Q.x,m)%m)%m;
    v = (Q.y - l * Q.x)%m;
    x = (l*l - a - P.x - Q.x)%m;
    y = -1*(l * x + v)%m;
    while(x<0) x+=m;
    while(y<0) y+=m;
    z=1;
    return;
  }else if(P.x == Q.x && P.y == Q.y){
    l = (3*P.x*P.x + 2*a*P.x + b)*inv_mod(2*P.y,m)%m;
    v = (Q.y - l*Q.x)%m;
    x = (l*l - a - 2*P.x)%m;
    y = -1*(l*x + v)%m;
    while(x<0) x+=m;
    while(y<0) y+=m;
    z=1;
    return;
  }else{
    x=z=0;
    y=1;
    return;
  }
}

// nP mod m.
Point Point::ECpower(long long n,long long m){
  Point Q = Point(x,y,z); // Q = (this->x,this->y,this->z)
  Point result = Point(); // result = (0,1,0)
  Point T;
  long long tmp=n;
  
  while(tmp>0){
    if(tmp%2 == 1)result.ECadd(result,Q,m);
    Q.ECadd(Q,Q,m);
    tmp/=2;
  }
  // x=result.x;
  // y=result.y;
  // z=result.z;
  return result;
}

Point Point::operator=(const Point& obj){
  this->x = obj.x;
  this->y = obj.y;
  this->z = obj.z;
  return *this;
}

int Point::operator==(const Point& obj){
  if(this->x == obj.x && this->y == obj.y && this->z == obj.z) return 1;
  else -1;
}
    


// Point Point::operator-(const Point& obj){
//   Point ans;
//   Point tmp(obj.x,-1*obj.y,obj.z);
//   ans.operator+(tmp);
//   return ans;
// }

// Point Point::operator-=(Point obj){
//   Point tmp(obj.x,-1*obj.y,obj.z);
//   return tmp;
// }
