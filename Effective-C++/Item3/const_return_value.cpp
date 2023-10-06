#include <iostream>

class Rational {
	private:
		double numerator;
		double denominator;
		double value;
	public:
		Rational() {
			this->numerator = 0;
			this->denominator = 1;
			this->value = 0;
		}
		Rational(double numerator, double denominator) {
			this->numerator = numerator;
			this->denominator = denominator;
			this->value = numerator / denominator;
		}
		double getValue() const {
			return this->value;
		}
};

const Rational operator*(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.getValue() * rhs.getValue(), 1);
}

using namespace std;

int main(void) {
	Rational a(1, 2);
	Rational b(2, 3);
	Rational c = a * b;
	Rational d;
	(a * b) = d; // error: (a * b) is a const value
	cout << c.getValue() << endl;
	cout << d.getValue() << endl;
	return 0;
}
