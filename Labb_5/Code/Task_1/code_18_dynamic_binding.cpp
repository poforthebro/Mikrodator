// pointers to base class
#include <iostream>
using namespace std;

class CPolygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
  };

class CRectangle: public CPolygon {
  public:
    int area ()
      { return (width * height); }
  };

class CTriangle: public CPolygon {
  public:
    int area ()
      { return (width * height / 2); }
  };

int main () {
  CRectangle rect;
  CTriangle trgl;
  CPolygon* ppoly1 = &rect;
  //Create a pointer that points to objects of base class CPolygon and assign reference
  //to rect to the pointer
  CPolygon* ppoly2 = &trgl;
  //Create a pointer that points to objects of base class CPolygon and assign reference
  //to trg1 to the pointer

  ppoly1->set_values (4,5); // Use the member function set_values of class CPolygon
  ppoly2->set_values (4,5); // Use the member function set_values of class CPolygon
  //ppoly1 = &trgl;
  //ppoly1->set_values (7,8); // Use the member function set_values of class CPolygon

  //rect.set_values(3,6);
  //trgl.set_values (3,6);
  cout << rect.area() << endl;  //Use the member function area of class CRectangle
  cout << trgl.area() << endl;  //Use the member function area of class CTriangle
  return 0;
}
