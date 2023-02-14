//QUESTION 7.21
#include <iostream>
using namespace std;

const int salespeople = 4;
const int products = 5;

void readSalesData(int sales[][products]);
void computeSalesTotals(int sales[][products], int salesTotals[]);
void computeProductTotals(int sales[][products], int productTotals[]);
void displayResults(int sales[][products], int salesTotals[], int productTotals[]);

int main()
{
    int sales[salespeople][products];
    int salesTotals[salespeople] = {0};
    int productTotals[products] = {0};

    readSalesData(sales);
    computeSalesTotals(sales, salesTotals);
    computeProductTotals(sales, productTotals);
    displayResults(sales, salesTotals, productTotals);

    return 0;
}

void readSalesData(int sales[][products])
{
    for (int i = 0; i < salespeople; i++)
    {
        cout << "Enter sales for salesperson " << i + 1 << ": " << endl;
        for (int j = 0; j < products; j++)
        {
            cout << "Product " << j + 1 << ": ";
            cin >> sales[i][j];
        }
    }
}

void computeSalesTotals(int sales[][products], int salesTotals[])
{
    for (int i = 0; i < salespeople; i++)
    {
        for (int j = 0; j < products; j++)
        {
            salesTotals[i] += sales[i][j];
        }
    }
}

void computeProductTotals(int sales[][products], int productTotals[])
{
    for (int i = 0; i < salespeople; i++)
    {
        for (int j = 0; j < products; j++)
        {
            productTotals[j] += sales[i][j];
        }
    }
}

void displayResults(int sales[][products], int salesTotals[], int productTotals[])
{
    cout << "Salesperson\tProduct 1\tProduct 2\tProduct 3\tProduct 4\tProduct 5\tTotal" << endl;
    for (int i = 0; i < salespeople; i++)
    {
        cout << i + 1 << "\t\t";
        for (int j = 0; j < products; j++)
        {
            cout << sales[i][j] << "\t\t";
        }
        cout << salesTotals[i] << endl;
    }
    cout << "Total\t\t";
    for (int i = 0; i < products; i++)
    {
        cout << productTotals[i] << "\t\t";
    }
}

