#include <bits/stdc++.h>

using namespace std;

long long int combination(long long int n, long long int m) {
	if (n == m || m == 0) return 1;
	return combination(n-1, m) + combination(n-1, m-1);
}

int main(void) {
	long long int n, m;
	scanf("%lld %lld", &n, &m);
	printf("combination: %lld\n", combination(n, m));
	return 0;
}
