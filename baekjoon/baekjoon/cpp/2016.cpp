#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	int order[10][5];
	int arr[10][5];
	int index[10];
	int companion[10];

	while (t--) {
		for (int i = 0; i < 5; i++) arr[0][i] = i + 5;

		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 5; j++) {
				scanf("%d", arr[i] + j);
				arr[i][j]--;
				order[i][arr[i][j] % 5] = j;
			}
		}

		int first;
		bool flag = true, Y = false;
		do {
			fill_n(companion, 10, -1);
			fill_n(index, 10, 0);
			for (int i = 0; i < 5; i++) order[0][arr[0][i] % 5] = i;

			while (true) {
				for (int i = 5; i < 10; i++) {
					if (index[i] != 5 && companion[i] == -1) {
						const int &favorite = arr[i][index[i]];

						if (companion[favorite] == -1) {
							companion[favorite] = i;
							companion[i] = favorite;
						}
						else if (order[favorite][i % 5] < order[favorite][companion[favorite] % 5]) {
							companion[companion[favorite]] = -1;
							companion[favorite] = i;
							companion[i] = favorite;
						}
						index[i]++;
					}
				}
				bool check = true;
				for (int i = 0; i < 10; i++) if (companion[i] == -1) check = false;
				if (check) break;
			}

			if (flag) {
				flag = false;
				first = companion[0];
			}
			else {
				if (companion[0] < first) Y = true;
			}
		} while (next_permutation(arr[0], arr[0] + 5));

		puts(Y ? "YES" : "NO");
	}
}