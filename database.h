#pragma once
#include "date.h"
#include <string>
#include "node.h"
#include <map>
#include <set>
using std::set;
using std::map;
class Database {
public:
	void Add(const Date& date, const string& event);
	ostream& Print(ostream& out);
	void Find(shared_ptr<Node> condition) const;
	int RemoveIf(shared_ptr<Node> condition);
	void Last(const Date& date) const;
private:
	map<Date,set<string>> task;
};