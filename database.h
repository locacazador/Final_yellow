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
using std::string;
struct Data {
	set<string> setOfEvents;
	vector<string> vectorOfEvents;
};
class Database {
public:
	void Add(const Date& date_, const string& event_);
	void Print(ostream& out) const;
	template <typename Condition> set<string> FindIf(shared_ptr<Node> condition) const {

	}
	template<typename Predicate> int RemoveIf(const Predicate& condition) {

	}
	string Last(const Date& date) const;
private:
	map<Date, Data> storage;
};

