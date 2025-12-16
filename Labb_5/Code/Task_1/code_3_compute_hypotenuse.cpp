#include<iostream>
using namespace std;
#include<cmath>
class vec{
    public: 
        int x;
        int y;
        int compute_hyp(int x, int y);
};
int vec::compute_hyp(int x, int y) {
    // function to compute hypotenuse of triangle
    return sqrt(pow(x,2)+pow(y,2));
}

int main() {
    vec triangle; // Create an object of triangle
    cout<< "Hypotenuse is "<<triangle.compute_hyp(3,4);  // Call the method with arguments
    return 0;
}
