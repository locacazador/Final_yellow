#pragma once
#include <string>
#include "date.h"
#include <memory>
using namespace std;
enum class Comparison {
	Less,
	LessOrEqual,
	Equal,
	GreaterOrEqual,
	Greater,
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
class DateComparisonNode: public Node {
public:
	DateComparisonNode(
		const Comparison& comp_,
		const Date& date_
	);
	bool Evaluate(const Date& date_, const string& event_) const override;
private:
	const Comparison comp;
	const Date date;

};
class EventComparisonNode : public Node {
	EventComparisonNode(
		const Comparison& comp_,
		const string& event_
	);
	bool Evaluate(const Date& date_, const string& event_) const override;
private:
	const Comparison comp;
	const string Event;
};
class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(
		const LogicalOperation& logicalOperation_,
		const shared_ptr<Node>& left_,
		const shared_ptr<Node>& right_
	);
	bool Evaluate(const Date& date_, const string& event_) const override;
private:
	const LogicalOperation logicalOperation;
	const shared_ptr<Node> lhs, rhs;
};