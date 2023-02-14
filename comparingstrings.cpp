//QUESTION 22.30
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str1[50];
    char str2[50];

    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    int result = strcmp(str1, str2);

    if (result == 0)
        cout << "The strings are equal." << endl;
    else if (result < 0)
        cout << "The first string is less than the second string." << endl;
    else
        cout << "The first string is greater than the second string." << endl;

    return 0;
}

