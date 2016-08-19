#include <cstdio>
#include <algorithm>

using namespace std;

int arry[10000];
int cnt = 0;

void numzinsu(int a, int i) {
    fill(arry, arry + 10000, 0);
	cnt = 0;
	while (a != 0) {
		arry[cnt++] = a%i;
		a /= i;
	}
}

bool check(int *temp) {
	for (int i = 0; i < cnt / 2; i++) if (temp[i] != temp[cnt - i - 1]) return false;
	return true;
}

int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int num;
		bool res;
		scanf("%d", &num);
		for (int i = 2; i <= 64; i++) {
			numzinsu(num, i);
			res = check(arry);
			if (res) break;
		}
		if (res) printf("1\n");
		else printf("0\n");
	}
}