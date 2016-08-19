#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int t, k, arr[101], n;
	scanf("%d", &t);
	set<pair<pair<int, int>, int> > st;

	while (t--) {
		st.clear();
		scanf("%d", &k);
		for (int i = 0; i < k; i++) scanf("%d", arr + i);
		sort(arr, arr + k);

		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);

			if (find(arr, arr + k, a) != arr + k && b != -1 && b * 60 + c <= 360) {
				st.insert(make_pair(make_pair(b * 60 + c, i), a));
			}
		}

		printf("%d %d\n", st.begin()->second, st.size());
	}
}