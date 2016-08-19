#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c;
	pair<int, int> cnt[81] = { {0,0} };
	scanf("%d %d %d", &a, &b, &c);
	for (int i = 0; i <= a + b + c; i++) cnt[i].second = -i;
	for (int i = 1; i <= a; i++) for (int j = 1; j <= b; j++) for (int k = 1; k <= c; k++) cnt[i + j + k].first++;
	sort(cnt, cnt + a + b + c + 1);
	printf("%d", -cnt[a + b + c].second);
}