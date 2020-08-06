#pragma once
#include "date.h"
#include <string>
#include "node.h"
#include <map>
#include <set>
#include <vector>
#include <algorithm>
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
	template <typename Condition> vector<string> FindIf(const Condition& condition) const { 
		vector<string> outVec;
		for (auto item : storage) {
			set<string> tmp = item.second.setOfEvents;
			int counter = 0;
			auto iterToCopy = stable_partition(item.second.setOfEvents.begin(), item.second.setOfEvents.end(),
				[&counter, &item, &condition](string a) {
					counter++;
					if (condition(item.first, a)) {
						return true;
					}
					else {
						return false;
					}
				}
			);
			auto iterSet = item.second.setOfEvents.begin();
			for (int i = 0; i != counter; ++i) {
				stringstream ss;
				auto date_ = item.first;
				ss << date_.makeString() << " " << *iterSet++ << endl;
				outVec.push_back(ss.str());
			}
			item.second.setOfEvents = tmp;
		}
		return outVec;
	}
	template<typename Predicate> int RemoveIf(const Predicate& condition) {
		int counter = 0;
		for (auto& mapIter : storage) {
			mapIter.second.setOfEvents.clear();
			auto iterToDel = stable_partition(mapIter.second.vectorOfEvents.begin(), mapIter.second.vectorOfEvents.end(),
				[&](string a) {
					if (condition(mapIter.first, a)) {
						counter++;
						return true;
					}
				});
			mapIter.second.vectorOfEvents.erase(mapIter.second.vectorOfEvents.begin(), iterToDel);
			set<string> setIn(mapIter.second.vectorOfEvents.begin(), mapIter.second.vectorOfEvents.end());
			mapIter.second.setOfEvents = setIn;
		}
		auto iterDeleteDate = stable_partition(storage.begin(), storage.end(), [&](pair<Date, Data> a) {
			if (a.second.setOfEvents.empty()) {
				return true;
			}
			else {
				return false;
			}
			});
		storage.erase(storage.begin(), iterDeleteDate);
		return counter;
	}
	string Last(const Date& date) const;
private:
	map<Date, Data> storage;
};