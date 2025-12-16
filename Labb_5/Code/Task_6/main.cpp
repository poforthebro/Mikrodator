#include <iostream>
#include <string>
using namespace std;

class woof {
    public:
    string name;
    int ayy;
};
int main() {
    // assign two things
  
    woof woof1;
    woof woof2;
    woof1.name = "John";
    woof2.name = "Tom";
    woof1.ayy = 20;
    woof2.ayy = 30;
    //Display
    cout << "Woof 1:" << woof1.name << woof1.ayy;
    cout << "\nWoof 2:" << woof2.name << woof2.ayy;
    //SWAP with pointers

    string* ptrName1 = &woof1.name;
    int* ptrayy1 = &woof1.ayy;

    string* ptrName2 = &woof2.name;
    int* ptrayy2 = &woof2.ayy;

    string tempName = *ptrName1;
    *ptrName1 = *ptrName2;
    *ptrName2 = tempName;

    int tempAyy  = *ptrayy1;
    *ptrayy1 = *ptrayy2;
    *ptrayy2 = tempAyy;
    cout << "\n";
    cout << "Woof 1:" << woof1.name << woof1.ayy;
    cout << "\nWoof 2:" << woof2.name << woof2.ayy;
}  
