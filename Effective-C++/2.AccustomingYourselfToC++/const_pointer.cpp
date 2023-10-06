#include <iostream>

using namespace std;

int main(void) {
	const char* const p = "Hello";
	cout << p << endl;
	// p[0] = 'A'; // error
	// p = "World"; // error
	return 0;
}
