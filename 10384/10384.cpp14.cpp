#include <cstdio>

int main() {
	int n, t;
	scanf("%d\n", &n);
	for (int c = 1; c <= n; c++) {
		int cnt[26] = {0};
		bool isT, isP, isD;
		isD = isT = isP = true;
		while ((t = getchar()) != 10) {
			if (t >= 'a' && t <= 'z') cnt[t - 'a']++;
			else if (t >= 'A' && t <= 'Z') cnt[t - 'A']++;
		}
		for (int b : cnt) {
			if (b < 1) isD = isT = isP = false;
			else if (b < 2) isD = isT = false;
			else if (b < 3) isT = false;
		}
		printf("Case %d: %s\n", c, isT ? "Triple pangram!!!" : isD ? "Double pangram!!" : isP ? "Pangram!" : "Not a pangram");
	}
}