#ifndef TestBase16
#define TestBase16
#include <iostream>
using namespace std;
const long MAX = 100;
class IntSet {
public:
	IntSet() { end = -1; }
	IntSet(long a[], long size) {
		end = (size >= MAX) ? (MAX - 1) : (size - 1);
		for (long i = 0; i <= end; i++) element[i] = a[i];
	}
	bool IsMemberOf(long a) {
		for (long i = 0; i <= end; i++) {
			if (element[i] == a) return true;
		}
		return false;
	}
	long GetEnd() { return end; }
	long GetElement(long i) { return element[i]; }
	bool IsSubSet(IntSet& set);
	IntSet Merge(IntSet& set);
	IntSet Intersect(IntSet& set);
	void Print() {
		for (long i = 0; i <= end; i++) {
			if ((i + 1) % 20 == 0) cout << element[i] << endl;
			else cout << element[i] << ' ';
		}
		cout << endl;
	}
private:
	long element[MAX];
	long end;
};
#endif