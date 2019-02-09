#include "TestBase17.h"
void Read(Matrix &m) {
	long k;
	for (long i = 0; i < M; i++) {
		for (long j = 0; j < N; j++) cin >> k, m.SetElement(i, j, k);
	}
}
long Matrix::MaxValue() const {
	long Max = array[0][0];
	for (long i = 0; i < M; i++) {
		for (long j = 0; j < N; j++) Max = (array[i][j] > Max) ? array[i][j] : Max;
	}
	return Max;
}
Matrix operator + (const Matrix& m1, const Matrix& m2) {
	Matrix tmp;
	for (long i = 0; i < M; i++) {
		for (long j = 0; j < N; j++) tmp.SetElement(i, j, m1.GetElement(i, j) + m2.GetElement(i, j));
	}
	return tmp;
}
Matrix operator - (const Matrix& m1, const Matrix& m2) {
	Matrix tmp;
	for (long i = 0; i < M; i++) {
		for (long j = 0; j < N; j++) tmp.SetElement(i, j, m1.GetElement(i, j) - m2.GetElement(i, j));
	}
	return tmp;
}
void Matrix::Transpose() {
	long tmp;
	for (long i = 0; i < M; i++) {
		for (long j = i + 1; j < N; j++) tmp = array[i][j], array[i][j] = array[j][i], array[j][i] = tmp;
	}
}
int main() {
	Matrix m;
	Read(m);
	m.Show("Matrix: ");
	cout << endl << "×î´óÔªËØ: " << m.MaxValue() << endl;
	m.Transpose();
	m.Show("After transpose: ");
	cout << endl;
	Matrix m1, m2, sum;
	Read(m1), Read(m2);
	sum = m1 + m2;
	m1.Show("Matrix m1: ");
	m2.Show("Matrix m2: ");
	sum.Show("Matrix sum = m1 + m2: ");
}