#include "date.h"
#include "node.h"
using namespace std;

bool EmptyNode::Evaluate(const Date& date, const string& event_) const {
	return false;
}
DateComprasionNode::DateComprasionNode(
	const Date& date_,
	const Comprasion& comp_)
	:
	date(date_), comp(comp_)
{}

bool DateComprasionNode::Evaluate (
	const Date& date_,
	const string& event_
) const {
	if (comp == Comprasion::Equal) {
		return date_ == date;
	}
	else if (comp == Comprasion::Less) {
		return date < date_;
	}
	else if (comp == Comprasion:: LessOrEqual) {
		return !(date_ < date);
	}
	else if (comp == Comprasion::More) {
		return date_ < date;
	}
	else if (comp == Comprasion::MoreOrEqual) {
		return !(date < date_);
	}
	else if (comp == Comprasion::NotEqual) {
		return !(date_ == date);
	}
}

LogicalOperationNode::LogicalOperationNode(
	const LogicalOperation& logicalOperation_,
	shared_ptr<const Node>& left_,
	shared_ptr<const Node>& right_
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

EventComprasionNode::EventComprasionNode(
	const string& event_,
	const Comprasion& comp_
	)
	:
	Event(event_), comp(comp_)
{}

bool EventComprasionNode::Evaluate(
	const Date& date_,
	const string& event_
) const {
	if (comp == Comprasion::Equal) {
		return Event == event_;
	}
	else if (comp == Comprasion::Less) {
		return Event < event_;
	}
	else if (comp == Comprasion::LessOrEqual) {
		return !(event_ < Event);
	}
	else if (comp == Comprasion::More) {
		return event_ < Event;
	}
	else if (comp == Comprasion::MoreOrEqual) {
		return !(Event < event_);
	}
	else if (comp == Comprasion::NotEqual) {
		return !(event_ == Event);
	}
}
