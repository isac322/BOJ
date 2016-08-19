#include <cstdio>
#include <algorithm>

using namespace std;


int main() {
	pair<int, int> a[9];
	int k[9];
	int r, c, d;
	scanf("%d %d\n", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			d = getchar();
			if (d >= '1' && d <= '9') {
				a[d - '1'] = make_pair(j, d - '1');
				getchar();
				getchar();
				j += 2;
			}
		}
		getchar();
	}
	sort(a, a + 9);
	int cnt = 1;
	k[a[8].second] = 1;
	for (int i = 7; i >= 0; i--) {
		if (a[i + 1].first != a[i].first) cnt++;
		k[a[i].second] = cnt;
	}
	for (int i = 0; i < 9; i++) printf("%d\n", k[i]);
}