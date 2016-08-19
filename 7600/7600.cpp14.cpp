#include <cstdio>

int main() {
	int cnt[26] = { 0 }, ch, s;
	while (true) {
		switch ((ch = getchar())) {
			case '#': return 0;
			case 10:
				s = 0;
				for (auto &v : cnt) {
					if (v) s++;
					v = 0;
				}
				printf("%d\n", s);
				break;
			default:
				if (ch >= 'A' && ch <= 'Z') cnt[ch - 'A']++;
				else if (ch >= 'a' && ch <= 'z') cnt[ch - 'a']++;
		}
	}
}