#include <bits/stdc++.h>

using namespace std;

long long int factorial(long long int n) {
	if (n == 0) return 1;
	return (n * (factorial(n - 1)));
}

int main(void) {
	long long int n;
	scanf("%lld", &n);
	printf("fac: %lld", factorial(n));
	return 0;
}
