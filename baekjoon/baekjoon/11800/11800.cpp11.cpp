#include <cstdio>
#include <algorithm>

using namespace std;

const char *same[] = { "Habb Yakk","Dobara","Dousa","Dorgy","Dabash","Dosh" };
const char *str[] = { "Yakk","Doh","Seh","Ghar","Bang","Sheesh" };

int main() {
	int t, a[3];
	scanf("%d", &t);
	for (int c = 1; c <= t; c++) {
		scanf("%d %d", a, a + 1);
		sort(a, a + 2);
		if (a[0] == a[1]) printf("Case %d: %s\n", c, same[a[0] - 1]);
		else if (a[0] == 5 && a[1] == 6) printf("Case %d: Sheesh Beesh\n", c);
		else printf("Case %d: %s %s\n", c, str[a[1] - 1], str[a[0] - 1]);
	}
}