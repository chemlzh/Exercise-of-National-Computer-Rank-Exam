#include <iostream>
using namespace std;
class MyClass {
public:
	MyClass() :count(0) { cout << "This object is "; }
	void Inc() {
		cout << "no. " << ++count << endl;
	}
private:
	int count;
};
int main() {
	MyClass *obj = new MyClass;
	obj->Inc();
	return 0;
}