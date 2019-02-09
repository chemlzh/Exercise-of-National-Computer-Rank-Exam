#include "TestBase16.h"
bool IntSet::IsSubSet(IntSet& set) {
	for (long i = 0; i <= set.GetEnd(); i++) {
		if (IsMemberOf(set.GetElement(i)) == false) return false;
	}
	return true;
}
IntSet IntSet::Merge(IntSet& set) {
	long *c = new long[end + set.GetEnd() + 2];
	long cnt = 0;
	for (long i = 0; i <= end; i++) c[cnt++] = element[i];
	for (long i = 0; i <= set.GetEnd(); i++) {
		if (IsMemberOf(set.GetElement(i)) == false) c[cnt++] = set.GetElement(i);
	}
	return IntSet(c, cnt);
}
IntSet IntSet::Intersect(IntSet& set) {
	long *c = new long[(end > set.GetEnd()) ? (set.GetEnd() + 1) : (end + 1)];
	long cnt = 0;
	for (long i = 0; i <= set.GetEnd(); i++) {
		if (IsMemberOf(set.GetElement(i)) == true) c[cnt++] = set.GetElement(i);
	}
	return IntSet(c, cnt);
}
int main() {
	long a[] = { 1,2,3,5,8,10 };
	long b[] = { 2,8 };
	IntSet set1(a, 6), set2(b, 2);
	cout << "����A: ";
	set1.Print();
	cout << "����B: ";
	set2.Print();
	if (set1.IsSubSet(set2)) cout << "����B�Ǽ���A���Ӽ�" << endl;
	else cout << "����B���Ǽ���A���Ӽ�" << endl;
	cout << endl;
	long c[] = { 1,2,3,5,8,10 };
	long d[] = { 2,8,9,11,30,56,67 };
	IntSet set3(c, 6), set4(d, 7), set5, set6;
	cout << "�󲢼�ǰ: " << endl;
	set3.Print();
	set4.Print();
	set5.Print();
	set5 = set3.Merge(set4);
	cout << "�󲢼���: " << endl;
	set3.Print();
	set4.Print();
	set5.Print();
	cout << endl;
	cout << "�󽻼�ǰ: " << endl;
	set3.Print();
	set4.Print();
	set6.Print();
	set6 = set3.Intersect(set4);
	cout << "�󽻼���: " << endl;
	set3.Print();
	set4.Print();
	set6.Print();
	cout << endl;
}