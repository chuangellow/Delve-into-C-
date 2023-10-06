#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<int> nums;
	const vector<int>::iterator iter = nums.begin();
	*iter = 10;
	++iter; // error: increment of const iterator 'iter'
	
	vector<int>::const_iterator citer = nums.begin();
	*citer = 10; // error: assignment of read-only location '* citer'
	++citer; // ok
	return 0;
}
