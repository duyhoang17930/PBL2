#include "DTime.h"

Day::Day(Date date, Time time) : date(date), time(time) {}

Day::Day(string datetime){
	int h, m, s, d, mo, y;

    istringstream timeStream(datetime.substr(0, 8));
    istringstream dateStream(datetime.substr(9));

    string temp;
    getline(timeStream, temp, ':');
    h = stoi(temp);
    getline(timeStream, temp, ':');
    m = stoi(temp);
    getline(timeStream, temp);
    s = stoi(temp);

    getline(dateStream, temp, '/');
    d = stoi(temp);
    getline(dateStream, temp, '/');
    mo = stoi(temp);
    getline(dateStream, temp);
    y = stoi(temp);
	
	time.setHour(h);
	time.setMinute(m);
	time.setSecond(s);
	date.setDay(d);
	date.setMonth(mo);
	date.setYear(y);
}

Day::~Day() {}

//ostream &operator<<(ostream &os, const Day &day)
//{
//    os << day.date << " " << day.time;
//    return os;
//}
//
//istream &operator>>(istream &is, Day &day)
//{
//    is >> day.date >> day.time;
//    return is;
//}

bool operator==(const Day &day1, const Day &day2)
{
    return day1.date == day2.date && day1.time == day2.time;
}

bool operator!=(const Day &day1, const Day &day2)
{
    return !(day1 == day2);
}

Day Day::operator+(int day)
{
    Day temp = *this;
    temp.date = temp.date + day;
    return temp;
}

Day Day::operator-(int day)
{
    Day temp = *this;
    temp.date = temp.date - day;
    return temp;
}

Day Day::operator+(const Day &other)
{
    Day temp = *this;
    temp.date = temp.date + other.date;
    temp.time = temp.time + other.time;
    return temp;
}

Day Day::operator-(const Day &other)
{
    Day temp = *this;
    temp.date = temp.date - other.date;
    temp.time = temp.time - other.time;
    return temp;
}

Day &Day::operator++()
{
    time++;
    if (time == Time(24, 0, 0))
    {
        time = Time(0, 0, 0);
        date++;
    }
    return *this;
}

Day &Day::operator--()
{
    time--;
    if (time == Time(0, 0, 0))
    {
        time = Time(23, 59, 59);
        date--;
    }
    return *this;
}

Day Day::operator--(int)
{
    Day temp = *this;
    --*this;
    return temp;
}

Day Day::operator++(int)
{
    Day temp = *this;
    ++*this;
    return temp;
}

Date Day::getDate() { return date; }

Time Day::getTime() { return time; }

void Day::setDate(Date date) { this->date = date; }

void Day::setTime(Time time) { this->time = time; }

bool Day::isValid() { return date.isValid() && time.isValid(); }

Day Day::getCurrentDay()
{
    Day temp;
    temp.date = temp.date.getCurrentDate();
    temp.time = temp.time.getCurrentTime();
    return temp;
}

string Day::getSDay(){
	return time.getTime()+" "+date.getDate();
}
