#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char map[9][9], tmp[9][9];
int n, m;

int dfs(int r, int c) {
    if (r < 0 or c < 0) return 0;
    else if (tmp[r][c] == 0 or tmp[r][c] == '1' or tmp[r][c] == '3') return 0;
    tmp[r][c] = '3';
    return 1 + dfs(r - 1, c) + dfs(r, c - 1) + dfs(r + 1, c) + dfs(r, c + 1);
}

int main() {
    int wall_cnt = 0;
    vector<pair<int, int>> vi_locs;

    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%c%*c", &map[i][j]);
            if (map[i][j] == '1') wall_cnt++;
            else if (map[i][j] == '2') vi_locs.emplace_back(i, j);
        }
    }

    const int tot = n * m;
    int ans = 0;
    for (int i = 0; i < tot; ++i) {
        if (map[i / m][i % m] != '0') continue;

        for (int j = i + 1; j < tot; ++j) {
            if (map[j / m][j % m] != '0') continue;

            for (int k = j + 1; k < tot; ++k) {
                if (map[k / m][k % m] != '0') continue;

                memcpy(tmp, map, 9 * 9);
                tmp[i / m][i % m] = tmp[j / m][j % m] = tmp[k / m][k % m] = '1';
                int vi_cnt = 0;
                for (auto &p: vi_locs) {
                    vi_cnt += dfs(p.first, p.second);
                }
                ans = max(ans, tot - wall_cnt - 3 - vi_cnt);
            }
        }
    }
    printf("%d\n", ans);
}