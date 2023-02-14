#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  cout << "Decimal" << setw(10) << "Octal" << setw(10) 
       << "Hexadecimal" << setw(10) << "Character" << endl;

  for (int i = 33; i <= 126; i++) {
    cout << dec << i << setw(10) << oct << i << setw(10) 
         << hex << i << setw(10) << (char) i << endl;
  }

  return 0;
}

