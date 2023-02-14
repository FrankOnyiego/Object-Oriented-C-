//QUESTION 22.60
#include <iostream>
#include <bitset>

unsigned int power2(unsigned int number, unsigned int pow) {
    return number << pow;
}

int main() {
    unsigned int number = 5;
    unsigned int pow = 3;
    unsigned int result = power2(number, pow);
    std::cout << number << " * 2^" << pow << " = " << result << std::endl;
    std::cout << std::bitset<32>(number) << " * 2^" << pow << " = " << std::bitset<32>(result) << std::endl;
    return 0;
}

