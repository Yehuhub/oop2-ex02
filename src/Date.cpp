#include "Date.h"

#include <sstream>
#include <vector>

Date::Date(int year, int month, int day): m_year(year), m_month(month), m_day(day){};

int Date::getYear()const{
    return m_year;
}
int Date::getMonth()const{
    return m_month;
}
int Date::getDay()const{
    return m_day;
}

std::string Date::getDate()const{
    std::string date ="";
    date += std::to_string(m_year) + "-" + std::to_string(m_month) + "-" + std::to_string(m_day);
    return date;
}

void Date::setDate(int year, int month, int day){
    m_year = year;
    m_month = month;
    m_day = day;
}

Date operator-(const Date& date, int year){
    return Date(date.getYear() - year, date.getMonth(), date.getDay());
}


bool operator<(const Date& l, const Date& r){
    if(l.getYear() < r.getYear())
        return true;
    else if(l.getYear() > r.getYear())
        return false;
    
    if(l.getMonth() < r.getMonth())
        return true;
    else if(l.getMonth() > r.getMonth())
        return false;

    return l.getDay() < r.getDay();
}

bool operator==(const Date& l, const Date& r){
    return(l.getYear() == r.getYear()) && (l.getMonth() == r.getMonth()) && (l.getDay() == r.getDay());
}

bool operator>(const Date& l, const Date& r){
    return (!(l<r) && !(l == r));
}

std::ostream& operator<<(std::ostream& os, const Date & obj){
    os << obj.getDate();
    return os;
}

std::istream& operator>>(std::istream& is, Date & obj){
    std::string input, token;
    char delimiter = '-';
    std::vector<int> values;

    is >> input;
    std::stringstream ss(input);

    while(getline(ss, token, delimiter)){
        values.push_back(std::stoi(token));
    }


    obj.setDate(values[0], values[1], values[2]);
    return is;
}