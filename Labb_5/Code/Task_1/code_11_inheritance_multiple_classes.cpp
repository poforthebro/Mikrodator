#include <iostream>
using namespace std;
// Base class
class class_A {
  public:
    void method_A() {
      cout << "Base class A. \n" ;
    }
};

// Another base class
class class_B {
  public:
    void method_B() {
      cout << "Base class B. \n" ;
    }
};

// Derived class from two base classes above
class derived_class: public class_A, public class_B {
};

int main() {
  derived_class example;
  example.method_A();
  example.method_B();
  return 0;
} 