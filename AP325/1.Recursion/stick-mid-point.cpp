#include <bits/stdc++.h>
#define MAXN 10000

using namespace std;

long long int cut(int p[MAXN], const int n, int left, int right) {
	if (right - left <= 1) return 0;
	int mid = (p[left] + p[right]) / 2;
	int idx = left;
	while (p[idx] < mid) idx++;
	if (p[idx-1] - p[left] >= p[right] - p[idx]) idx--;
	return (p[right] - p[left]) + cut(p, n, left, idx) + cut(p, n, idx, right);
}

int main(void) {
	int n, l;
	scanf("%d%d", &n, &l);
	int p[MAXN];
	p[0] = 0;
	p[n+1] = l;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	printf("%lld\n", cut(p, n, 0, n+1));
	return 0;
}
