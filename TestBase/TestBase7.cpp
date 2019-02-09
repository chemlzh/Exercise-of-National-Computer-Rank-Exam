#include <iostream>
using namespace std;
const int Size = 4;
template <typename T>
class MyClass
{
public:
	MyClass(T *p) {
		for (int i = 0; i < Size; i++) array[i] = p[i];
	}
	void Print();
private:
	T array[Size];
};

template <typename T>
void MyClass<T>::Print() {
	for (int i = 0; i < Size; i++) cout << array[i] << '\t';
}

int main() {
	int intArray[Size] = { 1,2,3,4 };
	MyClass <int> obj(intArray);
	obj.Print();
	cout << endl;
	return 0;
}