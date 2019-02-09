#include <iostream>
using namespace std;
class Book{
public:
	char *title, *writer;
	int num_pages;
	Book(const char *the_title, int pages, const char * the_writer) :num_pages(pages) {
		title = new char[strlen(the_title) + 1];
		strcpy(title, the_title);
		writer = new char[strlen(the_writer) + 1];
		strcpy(writer, the_writer);
	}
	~Book() { delete[] title, writer; }
	int numOfPages() const { return num_pages; }
	const char *theTitle() const { return title; }
	const char *theWriter() const { return writer; }
};
class TeachingMaterial:public Book{
	char *course;
public:
	TeachingMaterial(const char *the_title, int pages, const char *the_writer, const char *the_course) :Book(the_title, pages, the_writer) {
		course = new char[strlen(the_course) + 1];
		strcpy(course, the_course);
	}
	~TeachingMaterial() { delete[] course; }
	const char *theCourse() const { return course; }
};
int main() {
	TeachingMaterial a_book("C++语言程序设计", 299, "张三", "面向对象程序设计");
	cout << "教材名：" << a_book.theTitle() << endl;
	cout << "页数：" << a_book.numOfPages() << endl;
	cout << "作者：" << a_book.theWriter() << endl;
	cout << "相关课程：" << a_book.theCourse() << endl;
	return 0;
}