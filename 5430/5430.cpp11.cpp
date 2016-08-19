#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

char f[100001];

int main() {
	int t, n, c;
	scanf("%d\n", &t);
	deque<int> que;

	while (t--) {
		que.clear();
		gets(f);
		scanf("%d\n%*c", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%*c", &c);
			que.emplace_back(c);
		}

		bool back = true, e = true;
		for (int i = 0; f[i]; i++) {
			if (f[i] == 'R') back = !back;
			else if (que.empty()) {
				puts("error");
				e = false;
				break;
			}
			else if (back) que.pop_front();
			else que.pop_back();
		}
		gets(f);
		if (!e) continue;
		if (!que.empty()) {
			if (back) {
				printf("[%d", que.front());
				que.pop_front();
				while (!que.empty()) {
					printf(",%d", que.front());
					que.pop_front();
				}
				puts("]");
			}
			else {
				printf("[%d", que.back());
				que.pop_back();
				while (!que.empty()) {
					printf(",%d", que.back());
					que.pop_back();
				}
				puts("]");
			}
		}
		else puts("[]");
	}
}