#include <vector>
#include <iostream>

class PolyTerm {
 public:
  PolyTerm(double coefficient = 0, int exponent = 0) : coefficient(coefficient), exponent(exponent) {}
  double coefficient;
  int exponent;
};

class Polynomial {
 public:
  Polynomial() {}
  
  // constructor that takes in a vector of PolyTerms
  Polynomial(const std::vector<PolyTerm> &terms) : terms(terms) {}
  
  // getter function to access the terms of the polynomial
  std::vector<PolyTerm> getTerms() const {
    return terms;
  }
  
   void addTerm(const PolyTerm &term) {
    terms.push_back(term);
  }
  
  // setter function to set the terms of the polynomial
  void setTerms(const std::vector<PolyTerm> &newTerms) {
    terms = newTerms;
  }
  
  // overload the addition operator to add two polynomials
  Polynomial operator+(const Polynomial &b) const {
    Polynomial result;
    
    std::vector<PolyTerm>::const_iterator it1 = terms.begin(), it2 = b.terms.begin();
    while (it1 != terms.end() && it2 != b.terms.end()) {
      if (it1->exponent < it2->exponent) {
        result.terms.push_back(*it1);
        ++it1;
      } else if (it1->exponent > it2->exponent) {
        result.terms.push_back(*it2);
        ++it2;
      } else {
        result.terms.push_back(PolyTerm(it1->coefficient + it2->coefficient, it1->exponent));
        ++it1;
        ++it2;
      }
    }
    
    while (it1 != terms.end()) {
      result.terms.push_back(*it1);
      ++it1;
    }
    
    while (it2 != b.terms.end()) {
      result.terms.push_back(*it2);
      ++it2;
    }
    
    return result;
  }
  
  // overload the subtraction operator to subtract two polynomials
  Polynomial operator-(const Polynomial &b) const {
    Polynomial result;
    
    std::vector<PolyTerm>::const_iterator it1 = terms.begin(), it2 = b.terms.begin();
    while (it1 != terms.end() && it2 != b.terms.end()) {
      if (it1->exponent < it2->exponent) {
        result.terms.push_back(*it1);
        ++it1;
      } else if (it1->exponent > it2->exponent) {
        result.terms.push_back(PolyTerm(-it2->coefficient, it2->exponent));
        ++it2;
      } else {
        result.terms.push_back(PolyTerm(it1->coefficient - it2->coefficient, it1->exponent));
        ++it1;
        ++it2;
      }
    }
    
        while (it1 != terms.end()) {
      result.terms.push_back(*it1);
      ++it1;
    }
    
    while (it2 != b.terms.end()) {
      result.terms.push_back(PolyTerm(-it2->coefficient, it2->exponent));
      ++it2;
    }
    
    return result;
  }
  
  // overload the assignment operator to assign one polynomial to another
  Polynomial &operator=(const Polynomial &b) {
    terms = b.terms;
    return *this;
  }
  
  // overload the multiplication operator to multiply two polynomials
  Polynomial operator*(const Polynomial &b) const {
    Polynomial result;
    
    for (std::vector<PolyTerm>::const_iterator it1 = terms.begin(); it1 != terms.end(); ++it1) {
      for (std::vector<PolyTerm>::const_iterator it2 = b.terms.begin(); it2 != b.terms.end(); ++it2) {
        result.terms.push_back(PolyTerm(it1->coefficient * it2->coefficient, it1->exponent + it2->exponent));
      }
    }
    
    return result;
  }
  
  // overload the addition assignment operator
  Polynomial &operator+=(const Polynomial &b) {
    *this = *this + b;
    return *this;
  }
  
  // overload the subtraction assignment operator
  Polynomial &operator-=(const Polynomial &b) {
    *this = *this - b;
    return *this;
  }
  
  // overload the multiplication assignment operator
  Polynomial &operator*=(const Polynomial &b) {
    *this = *this * b;
    return *this;
  }
  
 private:
  std::vector<PolyTerm> terms;
};

std::ostream &operator<<(std::ostream &out, const Polynomial &p) {
  std::vector<PolyTerm> terms = p.getTerms();
  for (std::vector<PolyTerm>::iterator it = terms.begin(); it != terms.end(); ++it) {
    out << it->coefficient << "x^" << it->exponent << " ";
  }
  return out;
}



int main() {
  Polynomial p1, p2;
  
  p1.addTerm(PolyTerm(1, 2));
  p1.addTerm(PolyTerm(2, 3));
  
  p2.addTerm(PolyTerm(3, 1));
  p2.addTerm(PolyTerm(4, 2));
  
  Polynomial p3 = p1 + p2;
  std::cout << "p1 + p2 = " << p3 << std::endl;
  
  Polynomial p4 = p1 - p2;
  std::cout << "p1 - p2 = " << p4 << std::endl;
  
  Polynomial p5 = p1 * p2;
  std::cout << "p1 * p2 = " << p5 << std::endl;
  
  p1 += p2;
  std::cout << "p1 += p2: " << p1 << std::endl;
  
  p1 -= p2;
  std::cout << "p1 -= p2: " << p1 << std::endl;
  
  p1 *= p2;
  std::cout << "p1 *= p2: " << p1 << std::endl;
  
  return 0;
}


