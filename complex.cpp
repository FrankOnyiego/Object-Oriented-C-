//QUESTION 9.5

#include<iostream>
#include<string>

using namespace std;

class Complex{
  private:
    double realPart, imaginaryPart;

  public:
    Complex(double real=0, double imag=0){
      realPart = real;
      imaginaryPart = imag;
    }

    Complex operator+(const Complex &right){
      return Complex(realPart+right.realPart, imaginaryPart+right.imaginaryPart);
    }

    Complex operator-(const Complex &right){
      return Complex(realPart-right.realPart, imaginaryPart-right.imaginaryPart);
    }

    void display(){
      cout << "(" << realPart << ", " << imaginaryPart << ")" << endl;
    }
};

int main(){
  Complex c1(2, 3), c2(1, -2), c3;
  c3 = c1 + c2;
  cout << "c1 + c2 = ";
  c3.display();
  c3 = c1 - c2;
  cout << "c1 - c2 = ";
  c3.display();

  return 0;
}

