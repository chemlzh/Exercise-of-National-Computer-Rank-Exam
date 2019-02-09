#ifndef TestBase17
#define TestBase17
#include <iostream>
#include <iomanip>
using namespace std;
const long M = 18;
const long N = 18;
class Matrix {
	long array[M][N];
public:
	Matrix() {	}
	long GetElement(long i, long j) const { return array[i][j]; }
	void SetElement(long i, long j, long value) { array[i][j] = value; }
	long MaxValue() const;
	void Transpose();
	void Show(const char *s) const {
		cout << endl << s;
		for (long i = 0; i < M; i++) {
			cout << endl;
			for (long j = 0; j < N; j++) cout << setw(4) << array[i][j];
		}
	}
};
#endif