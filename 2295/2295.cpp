#include <cstdio>
#include <algorithm>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

int n, arr[1000];
unordered_map<int, int> map;

int main() {
	int m = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int &num = arr[i];
		scanf("%d", &num);

		for (int j = 0; j <= i; j++) map[num + arr[j]] = true;

		for (int j = 0; j < i; j++) {
			unordered_map<int, int>::iterator iter = map.find(num - arr[j]);
			if (iter != map.end()) {
				m = max(m, num);
				break;
			}
		}
	}

	printf("%d", m);
}