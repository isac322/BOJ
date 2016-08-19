#include <cstdio>
#include <algorithm>
#include <tr1/unordered_set>

using namespace std;
using namespace std::tr1;

int n, arr[1000];
unordered_set<int> set;

int main() {
	int m = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int &num = arr[i];
		scanf("%d", &num);

		for (int j = 0; j <= i; j++) set.insert(num + arr[j]);

		for (int j = 0; j < i; j++) {
			unordered_set<int>::iterator iter = set.find(num - arr[j]);
			if (iter != set.end()) {
				m = max(m, num);
				break;
			}
		}
	}

	printf("%d\n", m);
}