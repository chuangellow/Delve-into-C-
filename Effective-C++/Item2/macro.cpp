#include <iostream>
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

using namespace std;

void f(int n) {
	cout << "n: " << n << endl;
}

int main(void) {
	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b);
	CALL_WITH_MAX(++a, b+10);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	return 0;
}
