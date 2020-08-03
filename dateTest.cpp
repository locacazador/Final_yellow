#include "DateTest.h"
#include "test_runner.h"
void TestDate() {
	Date date(1, 1, 1);
	AssertEqual(date.makeString(), "0001-01-01", "MakeString");
	istringstream stream("2004-01-04");
	Date date2 = ParseDate(stream);
	AssertEqual(date2, Date(2004, 1, 4), "ParseDate");
	bool less = date < date2;
	Assert(less, "less");
	bool equal = date == Date(1, 1, 1);
	Assert(equal, "equal");
	stringstream os;
	os << date2;
	AssertEqual(os.str(), "2004-01-04", "<<");
	os.clear();
	Date date3(1, 15, 17);
	os << date3;
	AssertEqual(os.str(), "0001-15-17", "<< second");
}