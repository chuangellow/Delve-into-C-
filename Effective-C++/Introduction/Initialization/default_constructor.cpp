#include <iostream>

class Point {
	private:
		int x, y;
	public:
		Point();
		Point(int, int);
		double getDistanceToOrigin();
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

int main() {
	Point p1;
	Point p2(10, 20);
	std::cout << "Distance of p1 from origin: " << p1.getDistanceToOrigin() << std::endl;
	std::cout << "Distance of p2 from origin: " << p2.getDistanceToOrigin() << std::endl;
	return 0;
}
