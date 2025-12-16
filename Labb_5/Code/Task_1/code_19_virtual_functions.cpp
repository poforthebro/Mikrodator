// virtual members
#include <iostream>
using namespace std;

class CPolygon { //polymorphic class. CPolygon declares a virtual function.
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area ()  //Virtual function
      { return (0); }
      //{ return (2*width * height); }
  };

class CRectangle: public CPolygon {		//polymorphic class. CRectangle inherits a virtual function.
  public:
    int area ()
	{ return (width * height); }
  };

class CTriangle: public CPolygon {		//polymorphic class. CTriangle inherits a virtual function.
  public:
    int area ()
      { return (width * height / 2); }
  };

int main () {
  CRectangle rect;
  CTriangle trgl;
  CPolygon poly;
  CPolygon * ppoly1 = &rect;
  CPolygon * ppoly2 = &trgl;
  CPolygon * ppoly3 = &poly;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly3->set_values (4,5);
  cout << ppoly1->area() << endl; //Use the member function area() of class CRectangle
  cout << ppoly2->area() << endl; //Use the member function area() of class CTriangle
  cout << ppoly3->area() << endl; //Use the member function area() of class CPolygon
  return 0;
}
