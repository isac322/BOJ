#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	deque<int> que;
	que.push_back(n);

	for (int i = 1; i < n; i++) {
		que.push_front(n - i);
		int t = (n - i) % (i + 1);
		for (int j = 0; j < t; j++) {
			que.push_front(que.back());
			que.pop_back();
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", que.front());
		que.pop_front();
	}
}