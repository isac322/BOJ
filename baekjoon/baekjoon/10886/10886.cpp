#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, a = 0, b = 0, t;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		if (t) a++;
		else b++;
	}

	printf("Junhee is %scute!", a > b ? "" : "not ");
}