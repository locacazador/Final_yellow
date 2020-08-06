#include "date.h"
#include "node.h"
using namespace std;

bool EmptyNode::Evaluate(const Date& date, const string& event_) const {
	return true;
}
//DateComparisonNode::DateComparisonNode(
//	const Date& date_,
//	const Comparison comp_)
//	:
//	comp(comp_), date(date_)
//{}

DateComparisonNode::DateComparisonNode(const Comparison& comp_, const Date& date_)
	: comp(comp_), date(date_)
{
	
}

bool DateComparisonNode::Evaluate (
	const Date& date_,
	const string& event_
) const {
	if (comp == Comparison::Equal) {
		return date_ == date;
	}
	else if (comp == Comparison::Less) {
		return date < date_;
	}
	else if (comp == Comparison:: LessOrEqual) {
		return !(date_ < date);
	}
	else if (comp == Comparison::Greater) {
		return date_ < date;
	}
	else if (comp == Comparison::GreaterOrEqual) {
		return !(date < date_);
	}
	else if (comp == Comparison::NotEqual) {
		return !(date_ == date);
	}
}

LogicalOperationNode::LogicalOperationNode(
	const LogicalOperation& logicalOperation_,
	const shared_ptr<Node>& left_,
	const shared_ptr<Node>& right_
):
	logicalOperation(logicalOperation_),
	lhs(left_),
	rhs(right_)
{}

bool LogicalOperationNode::Evaluate(
	const Date& date_,
	const string& event_
) const {
	if (logicalOperation == LogicalOperation::And) {
		return lhs->Evaluate(date_, event_) && rhs->Evaluate(date_, event_);
	}
	else if (logicalOperation == LogicalOperation::Or) {
		return lhs->Evaluate(date_, event_) || rhs->Evaluate(date_, event_);
	}
}

EventComparisonNode::EventComparisonNode(
	const Comparison& comp_,
	const string& event_
	)
	:
	comp(comp_),
	Event(event_)
{}

bool EventComparisonNode::Evaluate(
	const Date& date_,
	const string& event_
) const {
	if (comp == Comparison::Equal) {
		return Event == event_;
	}
	else if (comp == Comparison::Less) {
		return Event < event_;
	}
	else if (comp == Comparison::LessOrEqual) {
		return !(event_ < Event);
	}
	else if (comp == Comparison::Greater) {
		return event_ < Event;
	}
	else if (comp == Comparison::GreaterOrEqual) {
		return !(Event < event_);
	}
	else if (comp == Comparison::NotEqual) {
		return !(event_ == Event);
	}
}
