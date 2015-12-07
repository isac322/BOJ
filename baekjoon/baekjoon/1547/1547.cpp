#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	bool cup[4] = {false, true};
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		swap(cup[a], cup[b]);
	}
	for (int i = 1; i <= 3; i++) if (cup[i]) printf("%d", i);
}