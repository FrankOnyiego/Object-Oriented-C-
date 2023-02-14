#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int dec, oct, hex;
    
    cout << "Enter an integer in decimal format: ";
    cin >> dec;
    cout << "In decimal format: " << dec << endl;
    cout << "In octal format: " << oct << dec << endl;
    cout << "In hexadecimal format: " << hex << dec << endl << endl;
    
    cout << "Enter an integer in octal format: ";
    cin >> oct;
    cout << "In decimal format: " << dec << oct << endl;
    cout << "In octal format: " << oct << endl;
    cout << "In hexadecimal format: " << hex << oct << endl << endl;
    
    cout << "Enter an integer in hexadecimal format: ";
    cin >> hex;
    cout << "In decimal format: " << dec << hex << endl;
    cout << "In octal format: " << oct << hex << endl;
    cout << "In hexadecimal format: " << hex << endl;
    
    return 0;
}

