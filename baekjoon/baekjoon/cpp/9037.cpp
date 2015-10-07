#include <cstdio>

using namespace std;

int cnt;
int n, people[10], tmp[10];

inline bool check() {
	for (int i = 1; i < n; i++) {
		if (people[i - 1] != people[i]) return false;
	}
	return people[0] == people[n - 1];
}

inline bool suply() {
	for (int i = 0; i < n; i++) if (people[i] & 1) people[i]++;
	return check();
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) scanf("%d", people + i);

		for (cnt = 0; !suply(); cnt++) {
			for (int i = 0; i < n; i++) {
				tmp[(i + 1) % n] = (people[i] >>= 1);
			}
			for (int i = 0; i < n; i++) people[i] += tmp[i];
		}

		printf("%d\n", cnt);
	}
}