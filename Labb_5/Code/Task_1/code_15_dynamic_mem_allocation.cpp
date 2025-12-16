// keyword operator
#include <iostream>
using namespace std;

class MyClass {
public:
  MyClass() {cout <<"Object constructed\n";}
  ~MyClass() {cout <<"Object destroyed: Function called when deallocating memory\n";}
};

int main () {
  MyClass * ptr; // Create pointer ptr to myclass class

  ptr = new MyClass[2]; // memory allocation through keyword new

  cout<<"Pointer value  = "<<ptr<<"\n";
  delete[] ptr;   // memory deallocation through keyword delete


  return 0;
}
