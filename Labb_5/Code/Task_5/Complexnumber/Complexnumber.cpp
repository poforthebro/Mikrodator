#include "Complexnumber.h"
#include <iostream>

using namespace std;
//CONSTRUCTANDDESTRUCT
Complex::Complex() : real(0.0), imag(0.0) {}
Complex::Complex(double re, double im) : real(re), imag(im) {}
Complex::~Complex() {}
//GETTERS
double Complex::getReal(void)  {
    return real;
}
double Complex::getImaginary(void) {
    return imag;
}
//SETTERS
void Complex::setReal(double re) {
    real = re;
}
void Complex::setImaginary(double im) {
    imag = im;
}
// WHAT IS GOING ON HERE?
//creating a new complex boi, using other complex bois, so this means that when the operator "+" is used with 2 complex bois
//it takes and basically makes Complex1.operator+(complex2) which you then define addition in.
Complex Complex::operator+(Complex& theComplex) {
    // IN ADDITION Z1 = a + bi, Z2= c+di
    // ZTOT = a+c+ (b+d)i
    double a = real;
    double b = imag;

    double c = theComplex.getReal();
    double d = theComplex.getImaginary();

    double newRe = a + c;
    double newIm = b + d;

    return Complex(newRe,newIm);

}
Complex Complex::operator-(Complex& theComplex) {
    double a = real;
    double b = imag;

    double c = theComplex.getReal();
    double d = theComplex.getImaginary();

    double newRe = a-c;
    double newIm = b-d;

    return Complex(newRe, newIm);

}
Complex Complex::operator*(Complex & theComplex) {
    double a = real;
    double b = imag;

    double c = theComplex.getReal();
    double d = theComplex.getImaginary();

    double newRe = (a * c) - (b * d);
    double newIm = (a * d) + (b * c);

    return Complex(newRe, newIm);

}
Complex Complex::operator/(Complex& theComplex) {

    double a = real;
    double b = imag;

    double c = theComplex.getReal();
    double d = theComplex.getImaginary();

    double newRe = ((a * c) + (b * d))/((c*c)+(d*d));
    double newIm = ((b * c)- (a * d)) / ((c * c) + (d * d));

    return Complex(newRe, newIm);

}

 //

int main()
{
    Complex Z1(3.0, 2.0);
    Complex Z2(3.0, 4.0);
    Complex ZTOTadd;
    Complex ZTOTsub;
    Complex ZTOTmul;
    Complex ZTOTdiv;
    ZTOTadd = Z1 + Z2;
    ZTOTsub = Z1 - Z2;
    ZTOTmul = Z1 * Z2;
    ZTOTdiv = Z1 / Z2;
    cout << ZTOTadd.getReal() << "  " << ZTOTadd.getImaginary() << "i\n";
    cout << ZTOTsub.getReal() << "  " << ZTOTsub.getImaginary() << "i\n";
    cout << ZTOTmul.getReal() << "  " << ZTOTmul.getImaginary() << "i\n";
    cout << ZTOTdiv.getReal() << "  " << ZTOTdiv.getImaginary() << "i\n";
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
