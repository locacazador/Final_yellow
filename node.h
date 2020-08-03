#pragma once
#include <string>
#include "date.h"
using namespace std;
enum class Comprasion {
	Less,
	LessOrEqual,
	Equal,
	MoreOrEqual,
	More,
	NotEqual
};
enum class LogicalOperation {
	Or,
	And
};
class Node {
public:
	virtual bool Evaluate(const Date& date_, const string& event_) const = 0;
};
class EmptyNode : public Node {
public:
	bool Evaluate(const Date& date_, const string& event_) const override;
};
class DateComprasionNode: public Node {
public:
	DateComprasionNode(
		const Date& date_,
		const Comprasion& comp_
	);
	bool Evaluate(const Date& date_, const string& event_) const override;
private:
	const Date date;
	const Comprasion comp;
};
class EventComprasionNode : public Node {
	EventComprasionNode(
		const string& event_,
		const Comprasion& comp_
	);
	bool Evaluate(const Date& date_, const string& event_) const override;
private:
	const string Event;
	const Comprasion comp;
};
class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(
		const LogicalOperation& logicalOperation_,
		shared_ptr<const Node>& left_,
		shared_ptr<const Node>& right_
	);
	bool Evaluate(const Date& date_, const string& event_) const override;
private:
	const LogicalOperation logicalOperation;
	shared_ptr<const Node> lhs, rhs;
};