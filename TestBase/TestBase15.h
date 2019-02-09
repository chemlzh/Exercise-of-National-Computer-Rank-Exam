#ifndef TestBase15
#define TestBase15
#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
public:
	MyString(const char *s) {
		size = strlen(s);
		str = new char[size + 1];
		strcpy(str, s);
	}
	~MyString() { delete[] str; }
	bool StartsWith(const char *s) const;
	bool EndsWith(const char *s) const;
private:
	char *str;
	long size;
};
#endif // !TestBase15