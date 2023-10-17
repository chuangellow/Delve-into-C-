#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> nums, int p) {
	int comb = 0;
	int size = nums.size();
	for (int s = 1; s < (1 << size); s++) {
		long long int prod = 1;
		for (int i = 0; i < size; i++) {
			if (s & (1 << i)) {
				prod = (prod * nums[i]) % p;
			}
		}
		comb += (prod == 1)? 1: 0;
	}
	return comb;
}

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> nums(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &nums[i]);
	}
	int p = 10009;
	int comb = solve(nums, p);
	printf("%d", comb);
	return 0;
}
