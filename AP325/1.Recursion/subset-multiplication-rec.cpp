#include <bits/stdc++.h>

using namespace std;

void solve(int pos, int prod, int *ans, vector<int> nums, int p, int n) {
	if (pos >= n) {
		if (prod == 1) *ans += 1;
		return;
	}
	solve(pos+1, (prod * nums.at(pos)) % p, ans, nums, p, n);
	solve(pos+1, prod, ans, nums, p, n);
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> nums(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &nums[i]);
	}
	int p = 10009;
	int *ans = new int;
	*ans = 0;
	solve(0, 1, ans, nums, p, n);
	printf("%d", *ans - 1);
	return 0;
}
