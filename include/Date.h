#pragma once

#include <iostream>

//class to represent dates as 3 integers
class Date{
public:
    Date(int year = 0, int month = 1, int day = 1);

    int getYear()const;
    int getMonth()const;
    int getDay()const;
    std::string getDate()const; //for printing purposes
    void setDate(int, int, int);

private:
    int m_year, m_month, m_day;
};

//operators overloading functions-----

//subtract int from year
Date operator-(const Date& date, int year);

//check equality
bool operator==(const Date& l, const Date& r);

//operator < (l < r, l came earlier)
bool operator<(const Date& l, const Date& r);

//operator < (l > r, r came earlier)
bool operator>(const Date& l, const Date& r);

std::ostream& operator<<(std::ostream& os, const Date & obj);

std::istream& operator>>(std::istream& is, Date & obj);