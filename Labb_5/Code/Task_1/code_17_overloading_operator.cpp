// vectors: overloading operators example
#include <iostream>
using namespace std;

class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int,int);
    CVector operator + (const CVector); //This is a function that returns a CVector. It uses pass-by-value.
	//One operand of the function is the object itself and the other operand is the parameter in the parentheses.
	//CVector operator + (CVector&); //Alternatively, this function uses pass-by-reference.
	//CVector operator + (const CVector& param); //Alternatively, this function uses pass-by-reference.
	//Declare the argument as const to be sure it is not modified.
};

CVector::CVector (int a, int b) {
  x = a;
  y = b;
}

//CVector CVector::operator+ (CVector& param) { //Alternatively, this function uses pass-by-reference.
//CVector CVector::operator+ (const CVector & param) { //Alternatively, this function uses pass-by-reference.
//Declare the argument as const to be sure it is not modified.



CVector CVector::operator+ (CVector param) {  //This function uses pass-by-value.
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return (temp);
}

int main () {
  CVector a (3,1);
  CVector b (1,2);
  CVector c;
  CVector d;
  c = a + b;
  d = a.operator + (b); //Using the function name explicitly, equivalent to a + b
  cout << c.x << "," << c.y << '\n';
  cout << d.x << "," << d.y;
  return 0;
}
