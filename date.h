#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
class Date {
public:
	Date(const int& year, const int& month,const int& day);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	string makeString();
	friend ostream& operator << (ostream& os, const Date& date);
private:
	int Year;
	int Month;
	int Day;
};
ostream& operator <<(ostream& os, Date& date);

Date ParseDate(istream& is);
bool operator ==(const Date& lhs, const Date& rhs);
bool operator < (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);