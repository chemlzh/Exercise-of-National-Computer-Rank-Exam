#include "TestBase12.h"
int main() {
	MiniString str1("World!"), str2("Hello "), str3;
	str3 = str1 + str2;
	str2 += str1;
	cout << str2 << endl;
	cout << str3 << endl;
}