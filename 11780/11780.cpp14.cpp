#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const unsigned INF = 987654321;
unsigned map[100][100], path[100][100];
vector<unsigned> arr;

void print(unsigned i, unsigned j) {
	auto &p = path[i][j];
	if (p != INF) {
		print(i, p);
		arr.emplace_back(p + 1);
		print(p, j);
	}
}

int main() {
	unsigned n, m, a, b, c;
	scanf("%u%u", &n, &m); 
	for (auto i = 0u; i < n; i++) {
		fill_n(map[i], n, INF);
		fill_n(path[i], n, INF);
		path[i][i] = map[i][i] = 0;
	}

	while (m--) {
		scanf("%u%u%u", &a, &b, &c);
		a--, b--;
		map[a][b] = min(map[a][b], c);
	}

	for (auto k = 0u; k < n; k++) {
		for (auto i = 0u; i < n; i++) {
			for (auto j = 0u; j < n; j++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	for (auto i = 0u; i < n; i++) {
		for (auto j = 0u; j < n; j++) printf("%u ", map[i][j] == INF ? 0u : map[i][j]);
		puts("");
	}
	for (auto i = 0u; i < n; i++) {
		for (auto j = 0u; j < n; j++) {
			if (i != j && map[i][j] != INF) {
				arr.clear();
				arr.emplace_back(i + 1);
				print(i, j);
				arr.emplace_back(j + 1);
				printf("%zd", arr.size());
				for (auto &p : arr) printf(" %u", p);
				puts("");
			}
			else puts("0");
		}
	}
}