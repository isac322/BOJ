#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int r, c, t, cnt = 0;
	unsigned char map[40][40];
	scanf("%d%d", &r, &c);

	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%hhu", map[i] + j);
	vector<unsigned char> vec;
	unsigned char tmp[9];
	for (int i = 0; i < r - 2; i++) {
		for (int j = 0; j < c - 2; j++) {
			tmp[0] = map[i][j];
			tmp[1] = map[i][j + 1];
			tmp[2] = map[i][j + 2];
			tmp[3] = map[i + 1][j];
			tmp[4] = map[i + 1][j + 1];
			tmp[5] = map[i + 1][j + 2];
			tmp[6] = map[i + 2][j];
			tmp[7] = map[i + 2][j + 1];
			tmp[8] = map[i + 2][j + 2];
			sort(tmp, tmp + 9);
			vec.push_back(tmp[4]);
		}
	}
	scanf("%d", &t);
	for (int i = 0; i < vec.size(); i++) if (vec[i] >= t) cnt++;
	printf("%d", cnt);
}