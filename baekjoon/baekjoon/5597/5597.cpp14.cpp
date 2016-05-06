#include <cstdio>

using namespace std;

int main() {
	bool check[31] = { false };
	int t;
	for (int i = 0; i < 28; i++) {
		scanf("%d", &t);
		check[t] = true;
	}
	for (int i = 1; i < 31; i++) if (!check[i]) printf("%d\n", i);
}