#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char map[26][26];

int dfs(int r, int c) {
    if (r < 0 or c < 0) return 0;
    else if (map[r][c] == 0 or map[r][c] == '0') return 0;

    map[r][c] = '0';
    return dfs(r - 1, c) + dfs(r, c - 1) + dfs(r + 1, c) + dfs(r, c + 1) + 1;
}

int main() {
    scanf("%d", &n);
    vector<int> result;

    for (int i = 0; i < n; ++i) scanf("%s", map[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int ret = dfs(i, j);
            if (ret != 0) result.emplace_back(ret);
        }
    }

    sort(result.begin(), result.end());
    printf("%lu\n", result.size());
    for (int &n: result) printf("%d\n", n);
}