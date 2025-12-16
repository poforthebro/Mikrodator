#include <iostream>
using namespace std;

class class_name {     // The class
  public:           // Access specifier
    class_name() {     // Constructor
      cout << "Constructor was invoked. \n";
    }
};

int main() {
  class_name example_obj;    // Create an object of class_name (this will call the constructor)
  return 0;
}