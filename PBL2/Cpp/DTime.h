#ifndef DTIME
#define DTIME 1

#include <iostream>
#include <string>
#include "date.h"
#include "time.h"

using namespace std;

class Day
{
protected:
    Date date;
    ::Time time;

public:
    Day(Date date = Date(), ::Time time = ::Time());
    Day(string);
    ~Day();

//    friend ostream &operator<<(ostream &os, const Day &day);
//    friend istream &operator>>(istream &is, Day &day);
    friend bool operator==(const Day &day1, const Day &day2);
    friend bool operator!=(const Day &day1, const Day &day2);
    Day operator+(int day);
    Day operator-(int day);
    Day operator+(const Day &other);
    Day operator-(const Day &other);
    Day &operator++();
    Day &operator--();
    Day operator++(int);
    Day operator--(int);

    Date getDate();
    ::Time getTime();
    void setDate(Date date);
    void setTime(::Time time);

    bool isValid();
    Day getCurrentDay();
    string getSDay();
};

#endif
