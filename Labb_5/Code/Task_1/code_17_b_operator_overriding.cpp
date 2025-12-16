
//Compile Time Polymorphism, Method Overriding

#include <iostream>
using namespace std;

class test {
public: 
    int i;
    string str;
test(){i=0;} // Constructor to initialize the object
void operator ++ () // Overloading ++ unitary operator. Example: ++object
 {
     i++; // No return
 }

 test operator + (test b)   // Overloading + binary operator. Example: object_1+ object_2
 {
     test c;
     c.i = i + b.i; // Operation on attribute 1
     c.str = str + " concatenated with " + b.str; // Operation on attribute 1
     return (c); // Return datatype is an object
 }


};



int main () {
    test obj; // Creating object obj of class test
    ++obj; // unitary operator on object
    cout<<obj.i<<endl;

// Test binary operator overloading
    test a1,a2,a3; // Creating three objects of class test
    
    a1.i = 10;  // Setting values to objects
    a2.i = 29;  // Setting values to objects
    a1.str = "Text A";
    a2.str = "Text B";

    a3 = a1 + a2;     // Using binary operator on objects
 
    // Output
    cout<<"Addition of two objects: integer variables are added: "<<a3.i<<endl;
    cout<<"Addition of two objects: string variables are appended: "<<a3.str<<endl;

  return 0;
}
