// example: class constructor
#include <iostream>
using namespace std;

class CRectangle {
    int width, height;
  public:
    CRectangle (int,int);	//Prototype of Constructor
    int area () {return (width*height);}
};

CRectangle::CRectangle (int a, int b) { //Definition of constructor
  width = a;
  height = b;
  cout << "ctor invoked" << endl;
}

int main () {
  CRectangle rect (3,4);
  //CRectangle rect; not allowed
  CRectangle rectb (5,6);
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  return 0;
}

