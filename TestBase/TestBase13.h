#ifndef TestBase13
#include <iostream>
using namespace std;
class ValArray {
	long *v;
	long size;
public:
	ValArray(const long *p, long n) :size(n) {
		v = new long[size];
		for (long i = 0; i < size; i++) v[i] = p[i];
	}
	ValArray() { delete[] v; }
	void cycle();
	void print(ostream& out) const {
		out << '{';
		for (long i = 0; i < size - 1; i++) out << v[i] << ',';
		out << v[size - 1] << '}';
	}
};
#endif // !TestBase13