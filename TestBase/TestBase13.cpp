#include "TestBase13.h"
void ValArray::cycle() {
	long tmp = v[0];
	for (long i = 0; i < size - 1; i++) v[i] = v[i + 1];
	v[size - 1] = tmp;
}
int main() {
	const long a[] = { 1,2,3,4,5 };
	ValArray v(a, 5);
	for (long i = 0; i < 5; i++) {
		cout << "v = ";
		v.print(cout);
		cout << endl;
		v.cycle();
	}
}