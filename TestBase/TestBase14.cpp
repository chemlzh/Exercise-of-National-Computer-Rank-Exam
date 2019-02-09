#include <iostream>
#include <cstring>
using namespace std;
class doc {
private:
	char *str;
	long counter[26];
	long length;
public:
	doc();
	void count();
	~doc();
	void print();
};

inline doc::doc() {
	long len = 1024, tmp;
	length = 0;
	str = new char[len+1];
	while (((tmp = getchar()) != EOF) && (length < len)) {
		str[length++] = tmp;
	}
	str[length] = '\0';
	memset(counter, 0, sizeof(counter));
}

inline void doc::count() {
	for (long i = 0; i < length; i++) {
		if ((str[i] >= 'A') && (str[i] <= 'Z')) counter[str[i] - 'A']++;
		else if ((str[i] >= 'a') && (str[i] <= 'z')) counter[str[i] - 'a']++;
	}
}

inline doc::~doc() {
	delete[] str;
}

inline void doc::print() {
	for (long i = 0; i < 26; i++) cout << counter[i] << endl;
}

int main() {
	doc myDoc;
	myDoc.count();
	myDoc.print();
}