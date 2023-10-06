#include <iostream>

using namespace std;

void f(int n) {
	cout << "n: " << n << endl;
}

template<typename T> inline void callWithMax(const T& a, const T& b) {
	f(a > b ? a : b);
}

int main(void) {
	int a = 5, b = 0;
	callWithMax(++a, b);
	callWithMax(++a, b+10);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	return 0;
}
