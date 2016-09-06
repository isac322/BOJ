#include <cstdio>
#include <vector>

using namespace std;

int n, s;
short map[1000][1000];
vector<short> arr;

void dfs(short idx) {
	for (int i = 0; i < n; i++) {
		while (map[idx][i]) {
			map[idx][i]--;
			map[i][idx]--;
			dfs(i);
		}
	}
	arr.emplace_back(++idx);
}

int main() {
	bool check = true;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		s = 0;
		for (int j = 0; j < n; j++) {
			scanf("%hd", map[i] + j);
			s += map[i][j];
		}
		if (s & 1) check = false;
	}
	if (!check) puts("-1");
	else {
		dfs(0);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) check = map[i][j] == 0;
		if (check) for (auto t : arr) printf("%hd ", t);
		else puts("-1");
	}
}