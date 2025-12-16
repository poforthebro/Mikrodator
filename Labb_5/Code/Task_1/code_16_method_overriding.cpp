// derived classes
//Compile Time Polymorphism, Method Overriding
//The function area in the base class and the derived classes has the same name.
//The function in the derived class overrides the function in the base class.
#include <iostream>
using namespace std;

class CPolygon {
  protected:
    int width, height; //Protected members can be accessed by derived classes.
  public:
    void set_values (int a, int b)
      { width=a; height=b;}
     int area ()
      { return (2* width * height); }
  };

class CRectangle: public CPolygon {  //Derived class
  public:
    int area ()
      { return (width * height); }
  };

class CTriangle: public CPolygon {  //Derived class
  public:
    int area ()
      { return (width * height / 2); }
  };


int main () {
  CPolygon polyg;
  CRectangle rect;
  CTriangle trgl;
  polyg.set_values(3,6);
  rect.set_values (4,5);
  //The Object rect includes also the function set_values and the protected members
  //of CPolygon besides its own members.
  trgl.set_values (4,5);
  cout << polyg.area() << endl;  //use the function in the base class
  cout << rect.area() << endl;   //use the function in the derived class
  cout << trgl.area() << endl;   //use the function in the derived class
  return 0;
}
