#include <iostream>
#include <bitset>
using namespace std;

int main() {
 int number = 9; 
 cout << "Before right-shift: " << bitset<32>(number) << endl;
 number = number >> 4;
 cout << "After right-shift: " << bitset<32>(number) << endl;
 return 0;
}

