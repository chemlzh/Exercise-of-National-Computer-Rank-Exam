#include <iostream>
using namespace std;
class Person {
	char *idcardno;
	char *name;
	bool ismale;
public:
	Person(const char *pid, const char *pname, bool pmale);
	~Person() {
		delete[] idcardno, name;
	}
	const char *getIDCardNO() const { return idcardno; }
	const char *getName() const {	return name; }
	void rename(const char *new_name);
	bool isMale() const { return ismale; }
};
class Staff :public Person {
	char *department;
	double salary;
public:
	Staff(const char *id_card_no, const char *p_name, bool is_male, const char *dept, double sal);
	void setDepartment(const char *d);
	double getSalary() const { return salary; }
	void setSalary(double s) { salary = s; }
};
Person::Person(const char *id_card_no, const char *p_name, bool is_male) {
	idcardno = new char[strlen(id_card_no) + 1];
	strcpy(idcardno, id_card_no);
	name = new char[strlen(p_name) + 1];
	strcpy(name, p_name);
}
void Person::rename(const char *new_name) {
	delete[] name;
	name = new char[strlen(new_name) + 1];
	strcpy(name, new_name);
}
Staff::Staff(const char *id_card_no, const char *p_name, bool is_male,
	const char *dept, double sal) :Person(id_card_no, p_name, is_male) {
	department = new char[strlen(dept) + 1];
	strcpy(department, dept);
	salary = sal;
}
void Staff::setDepartment(const char *dept) {
	delete[] department;
	department = new char[strlen(dept) + 1];
	strcpy(department, dept);
}
int main() {
	Staff Zhangsan("123456789012345", "张三", false, "人事部", 1234.56);
	Zhangsan.rename("张小丽");
	cout << Zhangsan.getName() << Zhangsan.getIDCardNO() << endl;
	return 0;
}