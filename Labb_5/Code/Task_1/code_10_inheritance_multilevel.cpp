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
class child_class: public base_class {
  public:
    string derived_variable = "Child class variable";
};

class grandchild_class: public child_class {
  public:
    string grandchild_variable = "Grand child class variable";
};

int main() {
  grandchild_class example;
  example.base_method();
  cout << example.base_variable + " and " + example.derived_variable;
  return 0;
} 