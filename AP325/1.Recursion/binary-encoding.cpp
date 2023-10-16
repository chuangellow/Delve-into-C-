#include <bits/stdc++.h>
#define MAXLEN 1110000

using namespace std;

typedef struct Result {
	long long int count;
	int pos;
} Result;

Result eval(int pos, char encoded_string[], int n) {
	if (pos >= strlen(encoded_string) || n == 0) return {0, pos};
	Result lu, ru, lb, rb;
	lu.count = ru.count = lb.count = rb.count = 0;
	lu.pos = ru.pos = lb.pos = rb.pos = pos;
	switch (encoded_string[pos]) {
		case '0':
			return {0, pos+1};
			break;
		case '1':
			return {n*n, pos+1};
			break;
		case '2':
			lu = eval(pos+1, encoded_string, n/2);
			ru = eval(lu.pos, encoded_string, n/2);
			lb = eval(ru.pos, encoded_string, n/2);
			rb = eval(lb.pos, encoded_string, n/2);
			return {lu.count+ru.count+lb.count+rb.count, rb.pos};
			break;
		default:
			return {0, pos+1};
			break;
	}
}

int main(void) {
	char encoded_string[MAXLEN];
	scanf("%s", encoded_string);
	int n;
	scanf("%d", &n);
	printf("%lld", eval(0, encoded_string, n).count);
	return 0;
}
