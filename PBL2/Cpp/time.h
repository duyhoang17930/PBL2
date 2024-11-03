#ifndef TIME
#define TIME 1

#include <iostream>
#include <conio.h>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

class Time
{
private:
    int hour, minute, second;
    char colon;

public:
    Time(int hour = 0, int minute = 0, int second = 0);
    ~Time();

    bool isZero();
    bool isValid();
    Time getCurrentTime();
    friend Time &operator++(Time &time);
    friend Time &operator--(Time &time);
    friend Time operator++(Time &time, int);
    friend Time operator--(Time &time, int);
    Time operator+(const Time &time);
    Time operator+(int minute2);
    Time operator-(const Time &time);
//    friend ostream &operator<<(ostream &os, const Time &time);
//    friend istream &operator>>(istream &is, Time &time);
	string getHaM();
	string getTime();
    friend bool operator==(const Time &time1, const Time &time2);
    friend bool operator!=(const Time &time1, const Time &time2);
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    int getHour();
    int getMinute();
    int getSecond();
};

#endif
