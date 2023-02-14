#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Variables to store data from both files
    int accountNumber, accountNum, dollarAmount;
    string name;
    double currentBalance;

    // Open the old master file and transaction file
    ifstream inOldMaster("oldmast.dat", ios::in);
    ifstream inTransaction("trans.dat", ios::in);
    // Open the new master file
    ofstream outNewMaster("newmast.dat", ios::out);

    // Read the first record from the old master file
    inOldMaster >> accountNumber >> name >> currentBalance;
    // Read the first record from the transaction file
    inTransaction >> accountNum >> dollarAmount;

    // Loop until both files reach the end-of-file marker
    while (!inOldMaster.eof() && !inTransaction.eof()) {
        // Check if the account number from the old master file is less than the one from the transaction file
        if (accountNumber < accountNum) {
            // If so, write the old master record to the new master file
            outNewMaster << accountNumber << " " << name << " " << currentBalance << endl;
            // Read the next record from the old master file
            inOldMaster >> accountNumber >> name >> currentBalance;
        }
        // Check if the account number from the transaction file is less than the one from the old master file
        else if (accountNum < accountNumber) {
            // If so, print an error message
            cout << "Unmatched transaction record for account number " << accountNum << endl;
            // Read the next record from the transaction file
            inTransaction >> accountNum >> dollarAmount;
        }
        // If the account numbers are equal, add the transaction amount to the current balance and write the record to the new master file
        else {
            currentBalance += dollarAmount;
            outNewMaster << accountNumber << " " << name << " " << currentBalance << endl;
            // Read the next record from both files
            inOldMaster >> accountNumber >> name >> currentBalance;
            inTransaction >> accountNum >> dollarAmount;
        }
    }

    // Write any remaining records from the old master file to the new master file
    while (!inOldMaster.eof()) {
        outNewMaster << accountNumber << " " << name << " " << currentBalance << endl;
        inOldMaster >> accountNumber >> name >> currentBalance;
    }

    // Check for any remaining transaction records and print an error message
    while (!inTransaction.eof()) {
        cout << "Unmatched transaction record for account number " << accountNum << endl;
        inTransaction >> accountNum >> dollarAmount;
    }

    // Close the files
    inOldMaster.close();
    inTransaction.close();
    outNewMaster.close();

    return 0;
}

