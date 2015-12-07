#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, t, m = 987654321;
	vector<int> vec;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		vec.push_back(t);
	}

	m = min(m, t);

	const int &len = vec.size();
	for (int i = 1; i <= m; i++) {
		bool check = true;
		for (int j = 0; j < len; j++) if (vec[j] % i) check = false;
		if (check) printf("%d\n", i);
	}
}