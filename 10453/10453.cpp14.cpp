#include <cstdio>

int indexA[50000], indexB[50000];
int main() {
	int t, n, aLen, bLen, sum;
	scanf("%d\n", &t);

	char ch;
	while (t--) {
		n = 0;
		for (aLen = 0; (ch = getchar()) != ' '; aLen++) {
			if (ch == 'b') indexA[n++] = aLen;
		}
		n = 0;
		for (bLen = 0; (ch = getchar()) != '\n' && ch != '\0'; bLen++) {
			if (ch == 'b') indexB[n++] = bLen;
		}

		if (bLen != aLen) {
			puts("-1");
			continue;
		}

		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += indexA[i] > indexB[i] ? indexA[i] - indexB[i] : indexB[i] - indexA[i];
		}

		printf("%d\n", sum);
	}
}