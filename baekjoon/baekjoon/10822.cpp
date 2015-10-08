#include <cstdio>

using namespace std;

int main() {
	int t, sum = 0;

	do {
		scanf("%d", &t);
		sum += t;
	} while (getchar() != '\n');
	printf("%d", sum);
}