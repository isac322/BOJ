#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(const int& l, const int& r) {
	if (l > r) return true;
	else return false;
}

int main() {
	int re = 0, n, a[50], b[50];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) scanf("%d", b + i);
	sort(a, a + n);
	sort(b, b + n, cmp);
	for (int i = 0; i < n; i++) re += a[i] * b[i];
	printf("%d", re);
}