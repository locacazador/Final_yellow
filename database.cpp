#include "database.h"
void Database::Add(const Date& date_, const string& event_) {
	if (!storage[date_].setOfEvents.count(event_)) {
		storage[date_].setOfEvents.insert(event_);
		storage[date_].vectorOfEvents.push_back(event_);
	}
}
void Database::Print(ostream& out) const
{
	for (const auto& item : storage) {
		for (const auto& event_ : item.second.vectorOfEvents) {
			cout << item.first << " " << event_ << endl;
		}
	}
}
string Database::Last(const Date& date_) const {
	auto iter = storage.upper_bound(date_);
	if (iter == storage.begin()) {
		return "No entries";
	}
	stringstream os;
	os << (--iter)->first << " " << iter->second.vectorOfEvents.back();
	return os.str();
}
