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

extern const int CONST = 13;
// y^2 = x^3 + ax^2 + bx + c
extern mpq_class Point::a;
extern mpq_class Point::b;
extern mpq_class Point::c;


// Default Constructor.
Point::Point(): x(0),y(0),z(1) {
}

// Constructor using initialize variables which you want.
Point::Point(mpq_class X,mpq_class Y,mpq_class Z): x(X),y(Y),z(Z){
}

Point::Point(std::string X,std::string Y,std::string Z): x(X),y(Y),z(Z){
}

void Point::copy(Point P){
  x = P.x;
  y = P.y;
  z = P.z;

  return;
}

// Showing coordinates of Point instance.
void Point::show(){
  std::cout << "x=" << x << "\n" << "y=" << y << "\n" << "z=" << z <<"\n";
  std::cout << "here is the end of showing coordinates of point.\n" << std::endl;
  return;
}

// Menber funciton to init instance.
// By default,initialized using original point.
void Point::init(){
  x=y="0";
  z="1";
}

// Initialize coordinates that you want.
void Point::set(mpq_class X,mpq_class Y,mpq_class Z){
  x = X;
  y = Y;
  z = Z;
}

// To reflect on x.
Point Point::reflect(){
  Point tmp(x,-1*y,z);
  return tmp;
}

// Additional two points.
// obj.canonicalize() is the function which reduction to this obj.
void Point::ECadd(Point P,Point Q){
  mpq_class l;
  mpq_class v;
  
  if(P.x != Q.x && P.y != Q.y){
    l = (P.y - Q.y)/(P.x - Q.x);
    v = Q.y - l * Q.x;
    x = l*l - a - P.x - Q.x;
    y = -1*(l * x + v);
    z = "1";
    x.canonicalize();
    y.canonicalize();
    return;
  }else if(P.x == Q.x && P.y == Q.y && P.z != 0){
    l = (3*P.x*P.x + 2*a*P.x + b)/(2*P.y);
    v = Q.y - l*Q.x;
    x = l*l - a - 2*P.x;
    y = -1*(l*x + v);
    x.canonicalize();
    y.canonicalize();
    z="1";
    return;
  }else{
    x=z="1";
    y="0";
    return;
  }
    
}

// operator overload on +.
Point Point::operator+(const Point& obj){
  // To contain return values.
  Point ans;
  mpq_class l;
  mpq_class v;

  if(x != obj.x && y != obj.y){
    l = (y - obj.y)/(x - obj.x);
    v = y - l * x;
    ans.x  = l*l - a - x - obj.x;
    ans.y = -1*(l*ans.x + v);
    ans.z = "1";
    ans.x.canonicalize();
    ans.y.canonicalize();
    return ans;
  }else if(x == obj.x && y == obj.y){
    l = (3*obj.x*obj.x + 2*a*obj.x +b)/(2*obj.y);
    v = y - l*obj.x;
    ans.x  = l*l - a - 2*x;
    ans.y = -1*(l*ans.x + v);
    ans.z = "1";
    ans.x.canonicalize();
    ans.y.canonicalize();
    return ans;
  }else{
    ans.x = ans.z = "1";
    ans.y = "0";
    return ans;
  }
}

void Point::check(Point P,Point Q){
  Point tmp;
  mpq_class x1,x2,x3;
  mpz_class num1,den1,num2,den2,num3,den3;
  mpq_class A,B,C;
  
  tmp = P + Q;
  // tmp.ECadd(P,Q);
   
  x1 = tmp.x;
  x2 = tmp.x - CONST;
  x3 = tmp.x + CONST;
  
  num1 = x1.get_num();
  den1 = x1.get_den();
  num2 = x2.get_num();
  den2 = x2.get_den();
  num3 = x3.get_num();
  den3 = x3.get_den();

  // There are conditions of a, b and c.
  // x1 = x.
  int condition_x1 = (mpz_perfect_square_p(num1.get_mpz_t()) && mpz_perfect_square_p(den1.get_mpz_t()));
  // x2 = x - const.
  int condition_x2 = (mpz_perfect_square_p(num2.get_mpz_t()) && mpz_perfect_square_p(den2.get_mpz_t()));
  // x3 = x + const/
  int condition_x3 = (mpz_perfect_square_p(num3.get_mpz_t()) && mpz_perfect_square_p(den3.get_mpz_t()));
 
  if(condition_x1){
    if(condition_x2){
      if(condition_x3){
	tmp.show();
	
	//tmp2 : x-n
	//tmp3 : x+n
	mpq_class tmp2,tmp3;
	// x-n
	num2 = sqrt(num2);
	den2 =  sqrt(den2);
	tmp2 = num2;
	tmp2 /= den2;
	// x+n
	num3 = sqrt(num3);
	den3 = sqrt(den3);
	tmp3 = num3;
	tmp3 /= den3;
	
	x1 = tmp2 + tmp3;
	x2 = tmp3 - tmp2;
	
	num1 = 2*sqrt(num1);
	den1 = sqrt(den1);
	x3 = num1;
	x3 /= den1;
	std::cout << "a=" << x1 << std::endl;
	std::cout << "b=" << x2 << std::endl;
	std::cout << "c=" << x3 << std::endl;
	std::cout << "Checking these answer is collect if the multiply is eauall to " 
		  << CONST << "." << std::endl;
	std::cout << x1*x2/2 << "\n" << std::endl;
      }
    }
  }
}
    


Point Point::operator-(const Point& obj){
  Point ans;
  Point tmp(obj.x,-1*obj.y,obj.z);
  ans.operator+(tmp);
  return ans;
}

// Point Point::operator=(const Point& obj){
//   Point tmp(obj.x,obj.y,obj.z);
//   return tmp;
// }

// Point Point::operator-=(Point obj){
//   Point tmp(obj.x,-1*obj.y,obj.z);
//   return tmp;
// }
