#include <iostream>
using namespace std;


// Base class
class base_class {
  public:
    string base_variable = "Base class variable";
    void base_method() {
      cout << "Method from base class called. \n" ;
    }
};

// Derived class
class derived_class: public base_class {
  public:
    string derived_variable = "Derived class variable";
};

int main() {
  derived_class example;
  example.base_method();
  cout << example.base_variable + " and " + example.derived_variable;
  return 0;
} 