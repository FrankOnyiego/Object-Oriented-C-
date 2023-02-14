#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() 
{
    // Open file for writing
    std::ofstream outFile("datasize.dat");

    // Check if file was opened successfully
    if (!outFile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    // Write headers for columns
    outFile << left << setw(15) << "Data Type" << right << setw(5) << "Size" << endl;
    outFile << setfill('-') << setw(20) << "" << setfill(' ') << endl;

    // Write data types and sizes
    outFile << left << setw(15) << "Char" << right << setw(5) << sizeof(char) << endl;
    outFile << left << setw(15) << "Unsigned char" << right << setw(5) << sizeof(unsigned char) << endl;
    outFile << left << setw(15) << "Short int" << right << setw(5) << sizeof(short int) << endl;
    outFile << left << setw(15) << "Unsigned short int" << right << setw(5) << sizeof(unsigned short int) << endl;
    outFile << left << setw(15) << "Int" << right << setw(5) << sizeof(int) << endl;
    outFile << left << setw(15) << "Unsigned int" << right << setw(5) << sizeof(unsigned int) << endl;
    outFile << left << setw(15) << "Long int" << right << setw(5) << sizeof(long int) << endl;
    outFile << left << setw(15) << "Unsigned long int" << right << setw(5) << sizeof(unsigned long int) << endl;
    outFile << left << setw(15) << "Float" << right << setw(5) << sizeof(float) << endl;
    outFile << left << setw(15) << "Double" << right << setw(5) << sizeof(double) << endl;
    outFile << left << setw(15) << "Long double" << right << setw(5) << sizeof(long double) << endl;

    // Close file
    outFile.close();

    cout << "Data written to file" << endl;

    return 0;
}

