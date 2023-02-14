#include <iostream>
#include <vector>


#include "Date.h"


class Employee {
public:
  Employee(const std::string& first, const std::string& last, const Date& birthdate)
    : firstName(first), lastName(last), birthDate(birthdate) {}
  virtual ~Employee() {}
  virtual double earnings() const = 0;
  virtual void print() const {
    std::cout << firstName << ' ' << lastName << " Born on ";
    birthDate.print();
  }
public:
  std::string firstName;
  std::string lastName;
  Date birthDate;
};

class SalariedEmployee : public Employee {
public:
  SalariedEmployee(const std::string& first, const std::string& last,
    const Date& birthdate, double salary)
    : Employee(first, last, birthdate), weeklySalary(salary) {}
  double earnings() const { return weeklySalary; }
  void print() const {
    Employee::print();
    std::cout << " Weekly Salary: " << weeklySalary << std::endl;
  }
private:
  double weeklySalary;
};

class HourlyEmployee : public Employee {
public:
  HourlyEmployee(const std::string& first, const std::string& last,
    const Date& birthdate, double hourlyWage, double hoursWorked)
    : Employee(first, last, birthdate), wage(hourlyWage), hours(hoursWorked) {}
  double earnings() const {
    if (hours <= 40)
      return hours * wage;
    else
      return 40 * wage + (hours - 40) * wage * 1.5;
  }
  void print() const {
    Employee::print();
    std::cout << " Hourly Wage: " << wage << " Hours worked: " << hours
      << std::endl;
  }
private:
  double wage;
  double hours;
};

int main() {
  std::vector<Employee*> employees;
  employees.push_back(
    new SalariedEmployee("John", "Doe", Date(1, 1, 1990), 800));
  employees.push_back(
    new HourlyEmployee("Jane", "Doe", Date(2, 2, 1991), 20, 40));

  // Date object to represent today's date
  Date today(2, 9, 2023);

  for (int i = 0; i < employees.size(); i++) {
    Employee* currentEmployee = employees[i];
    int currentMonth = currentEmployee->birthDate.getMonth();
    int currentYear = currentEmployee->birthDate.getYear();
    int currentDay = currentEmployee->birthDate.getDay();

    // Check if current month is the month of employee's birthday
    if (currentMonth == today.getMonth() && currentDay == today.getDay() &&
      currentYear == today.getYear()) {
    }
    currentEmployee->print();
    std::cout << "Earnings: " << currentEmployee->earnings() << std::endl;
  }

  return 0;
}

