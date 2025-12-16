// pure virtual members can be called
// from the abstract base class
#include <iostream>
using namespace std;

//abstract base class. An abstract base class cannot be used to create instances (objects) of it.
class CPolygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area (void) =0; //pure virtual function. The function is not defined.
    void printarea (void)
      { cout << this->area() << endl; }
      //Notice that "this" represents a pointer to the object whose code is being executed.
  };

class CRectangle: public CPolygon {  //polymorphic class.
  public:
    int area (void)
      { return (width * height); }
  };

class CTriangle: public CPolygon {   //polymorphic class.
  public:
    int area (void)
      { return (width * height / 2); }
  };

int main () {
  CRectangle rect;
  CTriangle trgl;
//  CPolygon poly; //Error: cannot instantiate abstract class
  CPolygon * ppoly1 = &rect; //Pointer points to rect
  ppoly1->set_values (4,5);
  ppoly1->printarea();  //printarea calls the function area of CRectangle

  ppoly1 = &trgl; //Pointer points to trgl
  ppoly1->set_values (3,4);
  ppoly1->printarea();	//printarea calls the function area of CTriangle
  //trgl.set_values (3,4);
  //trgl.printarea();
  return 0;
}
