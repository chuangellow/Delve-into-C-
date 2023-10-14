#include <bits/stdc++.h>

#define MAXLEN 1000

using namespace std;

int main(void) {
	char str[MAXLEN];
	scanf("%s", str);
	int count = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ')
			count++;
	}
	printf("count: %d\n", count);
	return 0;
}
