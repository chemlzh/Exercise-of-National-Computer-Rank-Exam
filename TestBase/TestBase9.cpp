#include <iostream>
#include <iomanip>
using namespace std;
template <int base>
class Number {
	int n;
public:
	Number(int i):n(i){}
	int advance(int k);
	int value() const { return n; }
};
class TimeOfDay {
public:
	Number <24> hours;
	Number <60> minutes;
	Number <60> seconds;
	Number<1000> milliseconds;
	TimeOfDay(int h = 0, int m = 0, int s = 0, int milli = 0) :hours(h), minutes(m), seconds(s), milliseconds(milli){}
	void advanceMillis(int k) { seconds.advance(milliseconds.advance(k)); }
	void advanceSeconds(int k) { minutes.advance(seconds.advance(k)); }
	void advanceMinutes(int k) { hours.advance(minutes.advance(k)); }
	void advanceHour(int k) { hours.advance(k); }
	void show() const {
		int c = cout.fill('0');
		cout << setw(2) << hours.value() << ':'
			<< setw(2) << minutes.value() << ':'
			<< setw(2) << seconds.value() << '.'
			<< setw(3) << milliseconds.value();
		cout.fill(c);
	}
};
template <int base>
int Number<base>::advance(int k) {
	n += k;
	int s = 0;
	while (n >= base) s++, n -= base;
	return s;
}
int main() {
	TimeOfDay time(1, 2, 3, 4);
	time.show();
	time.advanceHour(5);
	time.advanceSeconds(122);
	time.advanceMillis(1017);
	cout << endl;
	time.show();
	cout << endl;
	return 0;
}