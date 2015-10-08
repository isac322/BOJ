#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> *arr;
int e;

int calc(int node) {
	if (node == e) return 0;
	int re = 0, len = arr[node].size(), i = 0;
	if (len == 0) return 1;
	for (; i < len; i++) re += calc(arr[node][i]);
	return re;
}

int main() {
	int n, r, a;
	scanf("%d", &n);
	arr = new vector<int>[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == -1) r = i;
		else arr[a].push_back(i);
	}
	scanf("%d", &e);
	printf("%d", calc(r));
}