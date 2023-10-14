#include "mbed.h"
#include "Complex_C.hpp"





// TASK - write and test complexConjugate, complexNegate, complexSubtract, complexMagnitude, complexMultiply and complexDivide

int main() {
    printf("\n\nTASK312\n");

    //Create instance of a complex number
    ComplexNumber_C p = {2.0, 3.0};
    ComplexNumber_C q = {1.0, 1.0};
    complexDisplay("p", p);
    complexDisplay("q", q);
 
    ComplexNumber_C sum = complexAdd(p, q);
    complexDisplay("p+q", sum);

    ComplexNumber_C conj = complexConjugate(p);
    complexDisplay("p_", conj);

    ComplexNumber_C negate = complexNegate(q);
    complexDisplay("-q", negate);

    ComplexNumber_C subtract = complexSubtract(p, q);
    complexDisplay("p-q", subtract);

    double mag = complexMag(p);
    printf("|p| = %f\n", mag);

    ComplexNumber_C multiply = complexMultiply(p, q);
    complexDisplay("p * q", sum);

    ComplexNumber_C divide = complexDivide(p, q);
    complexDisplay("p/q", sum);

    complexConjugateInplace(p);

    complexNegateInplace(q);
    
    complexDisplay("p  coonjugate by ref ", p);
    complexDisplay("q  negate by ref ", q);
    while (true) {
    }
}
