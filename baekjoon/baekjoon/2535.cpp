#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<pair<short, short>, short> NAME;
vector<NAME> arr;
int nation[100];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		short na, st, s;
		scanf("%hd%hd%hd", &na, &st, &s);
		na--;

		arr.push_back(make_pair(make_pair(s, st), na));
	}

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	int cnt = 3;

	for (int i = 0; cnt && i < n; i++) {
		if (nation[arr[i].second] < 2) {
			nation[arr[i].second]++;
			printf("%d %d\n", arr[i].second + 1, arr[i].first.second);
			cnt--;
		}
	}
}