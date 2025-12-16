// static members in classes
#include <iostream>
using namespace std;

class test {
  public:
    static int n;  //static member, class variable
};

int test::n=24;    //Initialize the static member
                    //A static member can be accessed by classname and scope operator (::).
int main () {
  test a;

  cout << a.n << endl;
  cout << test::n << endl;  //A static member can be accessed by classname and scope operator (::).

  return 0;
}
