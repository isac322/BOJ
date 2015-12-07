#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	char re[11][11] = {0};
	int h, w, c, arr[9];
	scanf("%d %d %d", &h, &w, &c);
	for (int i = 0; i < c; i++) scanf("%d", arr + i);

	int index = 0;
	for (int i = c - 1; i >= 0; i--) {
		for (int j = 0; j < arr[i]; j++) {
			re[index / w][index % w] = char(i + 1) + '0';
			index++;
		}
	}

	for (int i = h - 1; i >= 0; i--) {
		if (i & 1) reverse(re[i], re[i] + w);
		puts(re[i]);
	}
}