#include "database.h"
void Database::Add(const Date& date, const string& event_) {
	task[date].push_back(event_);
}
int RemoveIf(shared_ptr<const Node> condition) {

}