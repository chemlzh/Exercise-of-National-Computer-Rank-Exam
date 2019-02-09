#ifndef TestBase12
#define TestBase12
#include <iostream>
#include <iomanip>
using namespace std;
class MiniString {
public:
	friend ostream &operator <<(ostream &output, const MiniString &s) {
		output << s.sPtr; return output;
	}
	friend istream &operator >>(istream &input, MiniString &s) {
		char temp[100];
		temp[0] = '\0';
		input >> setw(100) >> temp;
		long len = strlen(temp);
		if (len != 0) {
			s.length = len;
			if (s.sPtr != NULL) delete[] s.sPtr;
			s.sPtr = new char[s.length + 1];
			strcpy(s.sPtr, temp);
		}
		else s.sPtr = NULL;
		return input;
	}
	MiniString(const char *s=""):length((s!=NULL)?strlen(s):0) {
		SetString(s);
	}
	MiniString(const MiniString &s) {
		length = s.length;
		sPtr = new char[length + 1];
		strcpy(sPtr, s.sPtr);
	}
	~MiniString() { if (sPtr!=NULL) delete[] sPtr; }
	MiniString & operator +=( MiniString &s) {
		*this = *this + s;
		return *this;
	}
	MiniString operator +(MiniString &s) const{
		char *tmp;
		tmp = new char[length + s.length + 1];
		strcpy(tmp, sPtr), strcat(tmp, s.sPtr);
		return MiniString(tmp);
	}
	MiniString & operator = (const MiniString &s) {
		if (&s == this) return *this;
		if (s.sPtr != NULL) length = strlen(s.sPtr);
		else length = 0;
		sPtr = new char[length + 1];
		if (s.sPtr != NULL) strcpy(sPtr, s.sPtr);
		else sPtr = NULL;
		return *this;
	}
private:
	long length;
	char *sPtr;
	void SetString(const char *string2) {
		sPtr = new char[length + 1];
		if (string2 != NULL) strcpy(sPtr, string2);
		else sPtr = NULL;
	}
};
#endif // !TestBase12