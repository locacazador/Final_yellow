#pragma once
#include <string>
#include <iostream>
using namespace std;
class Date {
public:
	Date(int year, int month, int day)
		: Year(year),
		Month(month),
		Day(day)
	{}
	string makeString() {
		stringstream out("");
		out << Year << "-" <<
			Month << "-" <<
			Day;
	}
private:
	int Year;
	int Month;
	int Day;
};
ostream& operator <<(ostream& os, Date& date) {

}
Date ParseDate(istream& is) {

}