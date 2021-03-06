#include <cstdio>
class MyClass {
public:
	MyClass(long i) { member = i; }
	void SetMember(long m) { member = m; }
	long GetMember() { return member; }
	void Print() const { printf("%s%ld\n", "member=", member); }
private:
	long member;
};
int main(){
	MyClass obj1(0);
	obj1.Print();
	MyClass obj2(3);
	obj1.SetMember(5);
	obj2.SetMember(10);
	obj1.Print();
	obj2.Print();
}