#include <stdio.h>

int main() {
	char str[101];

	while (~scanf("%[^\n]%*c", str)) {
		int cnt[4] = { 0 };

		for (size_t i = 0; str[i]; i++) {
			char &t = str[i];

			if (t >= 'a' && t <= 'z') cnt[0]++;
			else if (t >= 'A' && t <= 'Z') cnt[1]++;
			else if (t >= '0'&&t <= '9') cnt[2]++;
			else cnt[3]++;
		}

		printf("%d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3]);
	}
}