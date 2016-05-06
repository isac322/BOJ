#include <cstdio>
#include <algorithm>

using namespace std;

char str[100001];
int index, sum;

int solve() {
	if (str[index] == ')') {
		index++;
		return 1;
	}
	int ret = 0;
	while (str[index++] == '(') ret += solve();
	sum += ret + 1;
	return ret ? ret : 1;
}

int main() {
	gets(str);
	while (str[index++] == '(') solve();
	printf("%d", sum);
}