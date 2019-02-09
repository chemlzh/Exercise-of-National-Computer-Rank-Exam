#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
	long size;
	char *buf;
public:
	String(long bufsize);
	void Strcpy(char *s);
	void Print() const;
	~String() {
		if (buf != NULL) delete[] buf;
	}
};
String::String(long bufsize) {
	size = bufsize;
	buf = new char[size];
	*buf = '\0';
}
void String::Strcpy(char *s) {
	char *p, *q;
	long len = strlen(s);
	if (len + 1 > size) {
		size = len + 1;
		p = q = new char[size];
		while ((*q = *s) != 0) { q++, s++; }
		delete[] buf;
		buf = p;
	}
	else {
		for (p = buf; (*p = *s) != 0; p++, s++);
	}
}
void String::Print() const {
	cout << size << '\t' << buf << endl;
}
int main() {
	char s[100];
	String str(32);
	cin.getline(s, 99);
	str.Strcpy(s);
	str.Print();
}