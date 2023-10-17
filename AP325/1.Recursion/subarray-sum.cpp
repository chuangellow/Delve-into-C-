#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> nums, int k) {
	vector<int> best_idx(2, 0);
	int best = k;
	int left = 0, right = 0, sum = 0;
	int size = nums.size();
	while (right < size) {
		sum += nums.at(right);
		while (sum > k) {
			sum -= nums.at(left);
			left++;
		}
		if (sum <= k && k - sum < best) {
			best = k - sum;
			best_idx.at(0) = left;
			best_idx.at(1) = right;
		}
		right++;
	}
	return best_idx;
}

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		nums.push_back(val);
	}
	int k;
	scanf("%d", &k);
	vector<int> best_idx = solve(nums, k);
	printf("A[%d:%d] is the best", best_idx[0], best_idx[1]);
	return 0;
}
