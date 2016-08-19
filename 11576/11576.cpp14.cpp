#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a, b, m, n1 = 0, n2 = 0, t;
	scanf("%d%d%d", &a, &b, &m);
	for (int i = 0; i < m; i++) {
		n1 *= a;
		scanf("%d", &t);
		n1 += t;
	}
	vector<int> arr;
	while (n1) {
		arr.emplace_back(n1 % b);
		n1 /= b;
	}
	reverse(arr.begin(), arr.end());
	for (auto a : arr) printf("%d ", a);
}