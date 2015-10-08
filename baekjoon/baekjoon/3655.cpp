#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

int n, len;
char str[25001];

int main() {
	int t;
	scanf("%d\n", &t);

	unordered_map<char, deque<int> > map;
	while (t--) {
		map.clear();
		scanf("%d\n", &n);
		gets(str);

		for (int i = 0; i < n; i++) map[str[i]].push_back(i);

		long long sum1 = 0;
		unordered_map<char, deque<int> >::iterator iter, end = map.end();
		for (iter = map.begin(); iter != end; iter++) {
			const int &num = iter->second.size();
			sum1 += 5 * ((long long) num*(num - 1)) >> 1;
		}

		long long sum2 = 0;
		for (int i = 0; i < n; i++) {
			deque<int> &que = map[str[i]];

			sum2 += ((long long) que.back() - que.front()) * 5;
			que.pop_front();
		}

		printf("%lld\n", sum2 - sum1);
	}
}