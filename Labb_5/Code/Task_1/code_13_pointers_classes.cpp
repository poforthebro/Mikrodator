// pointers to base class
#include <iostream>
using namespace std;
#include <cstring>
#include <string>
class test // simple class
{ public:
    int x;
    string str;
};

int main () {
int x=10;
int &ref_x = x; // ref_x is Alias variable for x
int z;
z = ref_x; // Using alias (reference) to use x


int* ptr1;
int* ptr2;

ptr1 = &x; // Assign address using "address of" that is & operator

cout<<"Pointer value ptr1 = "<<ptr1<<"\n";
cout<<"Data value x = "<< x <<"\n";
cout<<"Value poninted by pointer ptr1= "<< *ptr1 <<"\n\n";

ptr2=&z;// Assign address using "address of" that is & operator
cout<<"Pointer value = "<<ptr2<<"\n";
int y =*ptr2; // Assigning values using pointer
*ptr1 = *ptr2; // Direct assignment using pointers
*ptr1 = 3; // Assigning values using pointer

cout<<"value of pointer 1= "<< *ptr1 <<"\n";
cout<<"value of pointer 2 = "<< *ptr2 <<"\n";
cout<<"integer x = "<< x <<"\n";
cout<<"integer y = "<< y <<"\n\n";

// Pointer for classes 

test t1; // create object t1 of class test
t1.x = 64;
t1.str = "test string";
cout<<"t1.x = "<< t1.x <<"\n";
cout<<"t1.str = "<< t1.str <<"\n";
test* cptr;
cptr = &t1; 
cout<<"cptr t1 = "<< cptr <<"\n\n";


z = (*cptr).x;

cout<<"Dereferencing via * operator: x = "<< (*cptr).x <<"\n";
cout<<"Dereferencing via * operator: str= "<< (*cptr).str <<"\n\n";

cout<<"Dereferencing via arrow operator: x = "<< cptr->x <<"\n";
cout<<"Dereferencing via arrow operator: str = "<< cptr->str <<"\n";


 
  return 0;
}
