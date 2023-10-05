#include <iostream>

class Point {
	private:
		int x, y;
	public:
		Point();
		Point(int, int);
		int getX() { return x; }
		int getY() { return y; }
		double getDistanceToOrigin();
		Point(Point& p);
		Point& operator=(Point& p);
};

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

double Point::getDistanceToOrigin() {
	return sqrt(x*x + y*y);
}

Point::Point(Point &p) {
	this->x = p.x;
	this->y = p.y;
}

Point& Point::operator=(Point &p) {
	this->x = p.x;
	this->y = p.y;
	return *this;
}

double twoPointsDistance(Point &p1, Point &p2) {
	int x1 = p1.getX();
	int y1 = p1.getY();
	int x2 = p2.getX();
	int y2 = p2.getY();
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
	Point p1;
	Point p2(10, 20);
	std::cout << "Distance of p1 from origin: " << p1.getDistanceToOrigin() << std::endl;
	std::cout << "Distance of p2 from origin: " << p2.getDistanceToOrigin() << std::endl;
	Point p3(p2);
	std::cout << "Distance of p3 from origin: " << p3.getDistanceToOrigin() << std::endl;
	Point p4(30, 40);
	std::cout << "Distance of p4 from origin: " << p4.getDistanceToOrigin() << std::endl;
	std::cout << "Distance between p3 and p4: " << twoPointsDistance(p3, p4) << std::endl;
	return 0;
}
