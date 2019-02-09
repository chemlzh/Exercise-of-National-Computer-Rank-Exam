#include <iostream>
#include <cmath>
using namespace std;
class Shape {
public:
	virtual void draw() const = 0;
	virtual ~Shape() {}
};
class Point :public Shape {
public:
	Point(double x, double y) :x_(x), y_(y) {}
	virtual void draw() const;
	double distance(const Point pt) {
		return sqrt((x_ - pt.x_)*(x_ - pt.x_) + (y_ - pt.y_)*(y_ - pt.y_));
	}
private:
	double x_, y_;
};
void Point::draw() const {
	cout << '(' << x_ << ',' << y_ << ')' << endl;
}
int main() {
	Point * pt1 = new Point(3, 0);
	Point * pt2 = new Point(0, 4);
	Shape * s = pt1;
	s->draw();
	s = pt2;
	s->draw();
	cout << "Distance = " << pt1->distance(*pt2) << endl;
	delete pt1;
	delete pt2;
}