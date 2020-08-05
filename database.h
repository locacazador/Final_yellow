#pragma once
#include "date.h"
#include <string>
#include "node.h"
#include <map>
#include <set>
#include <vector>
using std::set;
using std::vector;
using std::map;
struct Data {
	set<string> setOfEvents;
	vector<string> vectorOfEvents;
};
class Database {
public:
	void Add(const Date& date, const string& event);
	void Print(ostream& out);
	void Find(shared_ptr<Node> condition) const;
	template<typename Predicate> int RemoveIf(const Predicate& condition) {

	}
	void Last(const Date& date) const;
private:
	map<Date, Data> storage;
};

