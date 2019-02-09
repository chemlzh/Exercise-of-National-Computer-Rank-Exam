#include "TestBase15.h"
bool MyString::StartsWith(const char *s) const {
	if (strlen(s) > size) return false;
	for (long i = 0; i < strlen(s); i++) {
		if (s[i] != str[i]) return false;
	}
	return true;
}
bool MyString::EndsWith(const char *s) const {
	if (strlen(s) > size) return false;
	for (long i = 0; i < strlen(s); i++) {
		if (s[i] != str[size - strlen(s) + i]) return false;
	}
	return true;
}
int main() {
	char s1[] = "abcde", s2[] = "abc", s3[] = "abd";
	char s4[] = "", s5[] = "abcde", s6[] = "abcdef";
	char s7[] = "abcde", s8[] = "cde", s9[] = "bde";
	char s10[] = "", s11[] = "abcde", s12[] = "abcdef";
	MyString str1(s1), str2(s7);
	cout << "s1 = " << s1 << endl
		<< "s2 = " << s2 << endl
		<< "s3 = " << s3 << endl
		<< "s4 = " << s4 << endl
		<< "s5 = " << s5 << endl
		<< "s6 = " << s6 << endl;
	cout << boolalpha
		<< "s1 starts with s2: " << str1.StartsWith(s2) << endl
		<< "s1 starts with s3: " << str1.StartsWith(s3) << endl
		<< "s1 starts with s4: " << str1.StartsWith(s4) << endl
		<< "s1 starts with s5: " << str1.StartsWith(s5) << endl
		<< "s1 starts with s6: " << str1.StartsWith(s6) << endl;
	cout << "s7 = " << s7 << endl
		<< "s8 = " << s8 << endl
		<< "s9 = " << s9 << endl
		<< "s10 = " << s10 << endl
		<< "s11 = " << s11 << endl
		<< "s12 = " << s12 << endl;
	cout << boolalpha
		<< "s7 ends with s8: " << str2.EndsWith(s8) << endl
		<< "s7 ends with s9: " << str2.EndsWith(s9) << endl
		<< "s7 ends with s10: " << str2.EndsWith(s10) << endl
		<< "s7 ends with s11: " << str2.EndsWith(s11) << endl
		<< "s7 ends with s12: " << str2.EndsWith(s12) << endl;
}