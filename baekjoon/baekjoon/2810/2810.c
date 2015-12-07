#include <stdio.h>

int main() {
	int len;
	scanf("%d\n", &len);
	int cnt = 1;
	for (int i = 0; i < len; i++) {
		char t = getchar();

		if (t == 'S') cnt++;
		else {
			getchar();
			i++;
			cnt++;
		}
	}

	printf("%d", cnt < len ? cnt : len);
}