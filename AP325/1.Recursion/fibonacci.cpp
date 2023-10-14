#include <bits/stdc++.h>

using namespace std;

long long int fibonacci(long long int n) {
	if (n == 0 || n == 1) return n;
	return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main(void) {
	long long int n;
	scanf("%lld", &n);
	printf("fib: %lld", fibonacci(n));
	return 0;
}
