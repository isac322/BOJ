#include <cstdio>
#include <deque>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	deque<int> que(n);
	for (int i = 0; i < n; i++) que[i] = i + 1;

	while (que.size() != 1) {
		que.pop_front();
		que.push_back(que.front());
		que.pop_front();
	}

	printf("%d", que[0]);
}