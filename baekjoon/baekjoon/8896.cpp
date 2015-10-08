#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main() {
	int t;
	scanf("%d\n", &t);
	char robot[10][31];

	while (t--) {
		int n, left;
		bool win[10] = { false };
		scanf("%d\n", &n);
		left = n;

		for (int i = 0; i < n; i++) gets(robot[i]);

		int k = strlen(robot[0]);

		vector<int> R, P, S;
		for (int i = 0; i < k; i++) {
			R.clear();
			P.clear();
			S.clear();

			for (int j = 0; j < n; j++) {
				if (!win[j]) {
					switch (robot[j][i]) {
						case 'R':
							R.push_back(j); break;
						case 'P':
							P.push_back(j); break;
						case 'S':
							S.push_back(j); break;
					}
				}
			}

			int r = R.size(), p = P.size(), s = S.size();
			if (r + p == left && r != 0 && p != 0) {
				for (int j = 0; j < r; j++) win[R[j]] = true;
				left -= r;
			}
			else if (r + s == left && r != 0 && s != 0) {
				for (int j = 0; j < s; j++) win[S[j]] = true;
				left -= s;
			}
			else if (p + s == left && s != 0 && p != 0) {
				for (int j = 0; j < p; j++) win[P[j]] = true;
				left -= p;
			}
		}

		if (left == 1) {
			for (int j = 0; j < n; j++) {
				if (!win[j]) {
					printf("%d\n", j + 1);
					break;
				}
			}
		}
		else puts("0");
	}
}