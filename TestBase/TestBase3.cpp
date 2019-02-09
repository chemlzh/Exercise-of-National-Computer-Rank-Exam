#include <iostream>
using namespace std;
class Date {
public:
	Date() :year(1), month(1), day(1) {}
	Date(long y, long m, long d) {
		year = y, month = m, day = d;
	}
	void print() const;
private:
	long year, month, day;
};
void Date::print() const {
	cout << year << '-' << month << '-' << day << endl;
}
int main() {
	Date national_day(1949, 10, 1);
	national_day.print();
}