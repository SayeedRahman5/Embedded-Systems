#include "Complex_C.hpp"
#include "mbed.h"

ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real += b.real;
    y.imag += b.imag;
    return y;
}

void complexDisplay(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}

ComplexNumber_C complexConjugate(const ComplexNumber_C a){
    ComplexNumber_C y = a;
    y.imag = -1 * y.imag;
    return y;
}

ComplexNumber_C complexNegate(const ComplexNumber_C a){
    ComplexNumber_C y = a;
    y.real = -1 * y.real;
    y.imag = -1 * y.imag;
    return y;
}

ComplexNumber_C complexSubtract(const ComplexNumber_C a, const ComplexNumber_C b){
    ComplexNumber_C aNegate = complexNegate(a);
    ComplexNumber_C y = complexAdd(aNegate, b);
    return y;
}

double complexMag(const ComplexNumber_C a){
    ComplexNumber_C y = a;
    double realSquare = y.real * y.real;
    double imagSquare = y.imag * y.imag;
    double mag = sqrt(realSquare + imagSquare);
    return mag;
}

ComplexNumber_C complexMultiply(const ComplexNumber_C a, const ComplexNumber_C b){
    ComplexNumber_C product;
    product.real = (a.real * b.real) + (a.imag * b.imag);
    product.imag = (a.real * b.imag) + (a.imag * b.real);
    return product;
}

ComplexNumber_C complexDivide(const ComplexNumber_C a, const ComplexNumber_C b){
    ComplexNumber_C Divide;
    double denom = (b.real * b.real) + (b.imag * b.imag);
    Divide.real = ((a.real * b.real) + (a.imag * b.imag))/denom;
    Divide.imag = ((a.real * b.imag) - (a.imag * b.real))/denom;
    return Divide;
}

///by ref functions:

void complexNegateInplace(ComplexNumber_C& u) {
    u.imag = -u.imag;
    u.real = -u.real;
}


void complexConjugateInplace(ComplexNumber_C& u) {
    u.imag = -u.imag;
}

