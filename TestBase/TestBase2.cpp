#include <iostream>
using namespace std;
long find(char s[], char t[]);
const long MAXLINE = 256;
int main() {
	char source[MAXLINE], target[MAXLINE];
	cout << "Please input a string for searching:\n";
	cin.getline(source, MAXLINE);
	cout << "Please input a string you want to find:\n";
	cin.getline(target, MAXLINE);
	long pos = find(source, target);
	if (pos >= 0) {
		cout << "Finding it. The target string is at index " << pos << " of the source string.\n";
	}
	else cout << "Not finding it.\n";
}
long find(char s[], char t[]) {
	long lenS = 0, lenT = 0, flag, i, j;
	while (s[lenS]&&lenS<MAXLINE) lenS++;
	while (t[lenT]&&lenT<MAXLINE) lenT++;
	for (i = 0; i < lenS; i++) {
		flag = 1;
		for (j = 0; j < lenT; j++) {
			if (s[i + j] != t[j]) flag = 0;
		}
		if (flag) return i;
	}
	return -1;
}