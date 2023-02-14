#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
public:
    Date(int m, int d, int y);
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }
    void print() const {
        std::cout << month << '/' << day << '/' << year;
    }

private:
    int month;
    int day;
    int year;
};

Date::Date(int m, int d, int y)
    : month(m), day(d), year(y)
{}

#endif

