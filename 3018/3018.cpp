#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	int e;
	scanf("%d", &e);

	set<int> s[101];
	vector<int> arr;

	for (int i = 0; i < e; i++) {
		arr.clear();

		int t;
		scanf("%d", &t);

		bool check = false;
		for (int j = 0; j < t; j++) {
			int k;

			scanf("%d", &k);

			arr.push_back(k);

			if (k == 1)check = true;
		}
		
		if (check) {
			for (int j = 0; j < t; j++) s[arr[j]].insert(i);
		} else {
			for (int j = 1; j < t; j++) {
				s[arr[0]].insert(s[arr[j]].begin(), s[arr[j]].end());
			}
			for (int j = 1; j < t; j++) {
				s[arr[j]] = s[arr[0]];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (s[1].size() == s[i].size()) {
			printf("%d\n", i);
		}
	}
}