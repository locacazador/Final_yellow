#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Date {
public:
	Date(int year, int month, int day)
		: Year(year),
		Month(month),
		Day(day)
	{}
	string makeString() {
		ostringstream out;
		out << Year << "-" <<
			Month << "-" <<
			Day;
		return out.str();
	}
private:
	int Year;
	int Month;
	int Day;
};
ostream& operator <<(ostream& os, Date& date) {
	string strOut = date.makeString();
	ostringstream out(strOut);
	return out;
}
Date ParseDate(istream& is) {
	int year_, month_, day_;
	is >> year_ >> month_ >> day_;
	Date date(year_, month_, day_);
}