#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int t, n;
	deque<int> que;
	scanf("%d", &t);
	char op[11];

	while (t--) {
		scanf("%s", op);

		switch (op[0]) {
			case 'p':
				switch (op[1]) {
					case 'u':
						scanf("%d", &n);
						if (op[5] == 'f') que.push_front(n);
						else que.push_back(n);
						break;
					case 'o':
						if (que.empty()) puts("-1");
						else if (op[4] == 'f') {
							printf("%d\n", que.front());
							que.pop_front();
						}
						else {
							printf("%d\n", que.back());
							que.pop_back();
						}
				}
				break;
			case 'f':
				printf("%d\n", que.empty() ? -1 : que.front());
				break;
			case 'b':
				printf("%d\n", que.empty() ? -1 : que.back());
				break;
			case 's':
				printf("%d\n", que.size());
				break;
			case 'e':
				puts(que.empty() ? "1" : "0");
		}
	}
}