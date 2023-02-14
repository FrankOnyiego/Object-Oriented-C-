// Fig. 10.15: Complex.cpp
#include <iostream>
#include <complex>
using namespace std;

// Fig. 10.14: Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
    explicit Complex(double = 0.0, double = 0.0); // constructor
    Complex operator+(const Complex &) const; // addition
    Complex operator-(const Complex &) const; // subtraction
    Complex operator*(const Complex &) const; // multiplication
    bool operator==(const Complex &) const; // equality comparison
    bool operator!=(const Complex &) const; // inequality comparison
    friend std::ostream &operator<<(std::ostream &, const Complex &);
    friend std::istream &operator>>(std::istream &, Complex &);
    void print() const; // output

private:
    double real; // real part
    double imaginary; // imaginary part
}; // end class Complex

#endif


// Constructor
Complex::Complex(double realPart, double imaginaryPart) : real(realPart), imaginary(imaginaryPart) {}

// Addition operator
Complex Complex::operator+(const Complex &operand2) const
{
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

// Subtraction operator
Complex Complex::operator-(const Complex &operand2) const
{
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

// Multiplication operator
Complex Complex::operator*(const Complex &operand2) const
{
    return Complex(real * operand2.real - imaginary * operand2.imaginary, real * operand2.imaginary + imaginary * operand2.real);
}

// Equality comparison operator
bool Complex::operator==(const Complex &operand2) const
{
    return (real == operand2.real) && (imaginary == operand2.imaginary);
}

// Inequality comparison operator
bool Complex::operator!=(const Complex &operand2) const
{
    return !(*this == operand2);
}

// Output operator
std::ostream &operator<<(std::ostream &output, const Complex &complex)
{
    output << "(" << complex.real << ", " << complex.imaginary << ")";
    return output;
}

// Input operator
std::istream &operator>>(std::istream &input, Complex &complex)
{
    input >> complex.real >> complex.imaginary;
    return input;
}

void Complex::print() const
{
    std::cout << "(" << real << ", " << imaginary << ")" << std::endl;
}



int main() {
   Complex x(1, 2), y(3, 4), z;

   cout << "Enter a complex number in the format (real, imaginary): ";
   cin >> z;
   cout << "z is ";
   cout << z;

   x = y + z;
   cout << "x is ";
   cout << x;

   x = y - z;
   cout << "x is ";
   cout << x;

   x = y * z;
   cout << "x is ";
   cout << x;

   if (y == z) {
      cout << "y and z are equal." << endl;
   } else {
      cout << "y and z are not equal." << endl;
   }

   return 0;
}
