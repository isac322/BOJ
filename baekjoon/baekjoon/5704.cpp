#include <cstdio>

using namespace std;

int main() {
	char str[201];
	int n;
	scanf("%d\n", &n);
	
	while (true) {
		int cnt[26] = { 0 };
		gets(str);
		if (str[0] == '*') break;

		for (int i = 0; str[i]; i++) cnt[str[i] - 'a']++;

		bool check = true;
		for (int i = 0; i < 26; i++) if (cnt[i] == 0) check = false;

		puts(check ? "Y" : "N");
	}
}