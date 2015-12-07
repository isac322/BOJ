#include <cstdio>
#include <algorithm>
#include <locale>
#include <cstring>

using namespace std;

struct element {
	char str[51], len, num;

	inline bool operator<(const element &val) const {
		if (len == val.len) {
			if (num == val.num) return strcmp(str, val.str) == -1;
			else return num < val.num;
		}
		else return len < val.len;
	}
} arr[1000] = { 0 };

int main() {
	int n;
	scanf("%d\n", &n);

	int index;
	char ch;
	for (int i = 0; i < n; i++) {
		index = 0;

		element &p = arr[i];

		while ((ch = getchar()) != 10) {
			p.str[index++] = ch;
			if (isdigit(ch)) p.num += ch - '0';
		}
		p.len = index;
	}

	sort(arr, arr + n);
	for (int i = 0; i < n; i++) puts(arr[i].str);
}