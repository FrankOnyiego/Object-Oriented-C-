#include <iostream>
#include <string>

using namespace std;

class Employee {
    private:
        string firstName;
        string lastName;
        int monthlySalary;
    public:
        Employee(string fn, string ln, int ms) {
            firstName = fn;
            lastName = ln;
            if (ms > 0) {
                monthlySalary = ms;
            } else {
                monthlySalary = 0;
            }
        }
        void setFirstName(string fn) {
            firstName = fn;
        }
        string getFirstName() {
            return firstName;
        }
        void setLastName(string ln) {
            lastName = ln;
        }
        string getLastName() {
            return lastName;
        }
        void setMonthlySalary(int ms) {
            if (ms > 0) {
                monthlySalary = ms;
            } else {
                monthlySalary = 0;
            }
        }
        int getMonthlySalary() {
            return monthlySalary;
        }
};

int main() {
    Employee emp1("John", "Doe", 2000);
    Employee emp2("Jane", "Doe", 3000);

    cout << "Employee 1: " << emp1.getFirstName() << " " << emp1.getLastName() << endl;
    cout << "Yearly Salary: " << emp1.getMonthlySalary() * 12 << endl;

    cout << "Employee 2: " << emp2.getFirstName() << " " << emp2.getLastName() << endl;
    cout << "Yearly Salary: " << emp2.getMonthlySalary() * 12 << endl;

    emp1.setMonthlySalary(emp1.getMonthlySalary() * 1.1);
    emp2.setMonthlySalary(emp2.getMonthlySalary() * 1.1);

    cout << "Employee 1: " << emp1.getFirstName() << " " << emp1.getLastName() << endl;
    cout << "Yearly Salary: " << emp1.getMonthlySalary() * 12 << endl;

    cout << "Employee 2: " << emp2.getFirstName() << " " << emp2.getLastName() << endl;
    cout << "Yearly Salary: " << emp2.getMonthlySalary() * 12 << endl;

    return 0;
}

