// keyword operator
#include <iostream>
using namespace std;

class example
{
private:
    int x;
public:
    example(){ x = 5; };

    int getData() 
    {   
        cout<<"Pointer value via This = "<<this<<"\n";
        return (*this).x;  // Using keyword THIS
    }
};

int main()
{
    example var;
    int i;
    example* ptr; //define pointer type variable
    ptr = &var; // ptr refers to object var 
    cout<<"Pointer value to object = "<<ptr<<"\n"; 
    i = var.getData();  // call method in class

    return 0;
}