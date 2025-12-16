#include <iostream>
using namespace std;


class class_name {// The class  
public: // Access specifier    
void class_method() 
	{ // Method/function defined inside the class      
    cout << "Created class method inside class. \n"; 
    }

void class_method_outside();    // Method/function declaration
};

    

// Method/function definition outside the class
void class_name::class_method_outside() 
{
    cout << "Created class method outside class.\n";
}
    
int main (){
// variable declaration
class_name example1;
example1.class_method();
example1.class_method_outside();

}
