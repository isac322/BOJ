#include <queue>
#include <cstdio>

using namespace std;

int main() {
	int a, n, sum = 0;
	scanf("%d", &n);
	priority_queue<int> q;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		q.emplace(-a);
	}
	while (q.size() > 1) {
		int a = q.top();
		q.pop();
		sum -= (a += q.top());
		q.pop();
		q.emplace(a);
	}
	printf("%d", sum);
}