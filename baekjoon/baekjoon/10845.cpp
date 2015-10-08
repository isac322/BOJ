#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	queue<int> que;
	int n;
	scanf("%d", &n);

	char str[9];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);

		switch (str[0]) {
			case 's':
				printf("%d\n", que.size());
				break;
			case 'e':
				printf("%d\n", que.empty() ? 1 : 0);
				break;
			case 'f':
				if (que.empty()) puts("-1");
				else printf("%d\n", que.front());
				break;
			case 'b':
				if (que.empty()) puts("-1");
				else printf("%d\n", que.back());
				break;
			case 'p':
				if (str[1] == 'u') {
					int t;
					scanf("%d", &t);

					que.push(t);
				} else {
					if (que.empty()) {
						puts("-1");
					} else {
						printf("%d\n", que.front());
						que.pop();
					}
				}
		}
	}
}