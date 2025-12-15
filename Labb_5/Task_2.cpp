#include<stdio.h>
#include<cmath>

class triangle{
    private:
    int x;
    int y;

    int hypotenuse(int x, int y) {
    return sqrt(x*x + y*y);
    }

    public:

    void set(int varX, int varY) {
        x = varX;
        y = varY;
       printf("X and y values have been set\n");

    }

    int getX() {
        int varX = x;
        return varX;
    }

    int getY() {
        int varY = y;
        return varY;
    }

    int getHyp() {
        double hyp = hypotenuse(x, y);
        return hyp;
    }

};



int main() {
    triangle t1;
    t1.set(3, 4);


    printf("Values: ");
    printf("x: %d y: %d, hyp: %d \n", t1.getX(), t1.getY(), t1.getHyp()); 

}
