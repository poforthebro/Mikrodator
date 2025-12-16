// Function overloading
#include <iostream>
using namespace std;


class example
{
    public:

    int add(int x) // function with one integer parameter
    {
        cout << "Output of function is itself: " << x << endl;
        return x;
    }
      
    // function with same name but two integer parameters
    int add(int x, int y)
    {
        cout << "Output of function is sum of variables: " << x + y << endl;
        return x+y;
    }
};
  
int main() {
      
    example obj1;       // Create object obj1 of class example
      
    obj1.add(2);       // Call function with one argument

    obj1.add(1,2);     // Call function with two arguments

    return 0;
}