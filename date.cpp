#include "date.h"
Date::Date(const int& year_,
	const int& month_,
	const int& day_
	)
	:
	Year(year_), Month(month_), Day(day_)
{}
Date ParseDate(istream& is) {
	int year_, month_, day_;
	is >> year_;
	is.ignore(1);
	is >> month_;
	is.ignore(1);
	is >> day_;
	return Date(year_, month_, day_);
}
ostream& operator <<(ostream& os, Date& date) {
	string strOut = date.makeString();
	ostringstream out(strOut);
	return out;
}
string Date::makeString() {
	ostringstream out;
	out << setw(4) << setfill('0')
		<< Year << "-" <<
		setw(2) << setfill('0') <<
		Month << "-" << setw(2) <<
		setfill('0') << Day;
	return out.str();
}
int Date::getYear() const {
	return Year;
}
int Date::getDay() const {
	return Day;
}
int Date::getMonth() const {
	return Month;
}
bool operator == (const Date& lhs, const Date& rhs) {
	if (lhs.getYear() == rhs.getYear()) {
		if (lhs.getMonth() == rhs.getMonth()) {
			return lhs.getDay() == rhs.getDay();
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool operator < (const Date& lhs, const Date& rhs) {
	if (lhs.getYear() == rhs.getYear()) {
		if (lhs.getMonth() == rhs.getMonth()) {
			return lhs.getDay() < rhs.getDay();
		}
		else {
			return lhs.getMonth() < rhs.getMonth();
		}
	}
	else {
		return lhs.getYear() < rhs.getYear();
	}
}