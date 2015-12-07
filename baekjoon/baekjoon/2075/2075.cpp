#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int main() {
	priority_queue< int, vector<int>, greater<int> > heap;
	int n, t, a;
	scanf("%d", &n);
	for (int i = 0; i < n * n; i++) {
		scanf("%d", &t);
		if (heap.size() < n) heap.push(t);
		else {
			a = heap.top();
			if (a < t) {
				heap.pop();
				heap.push(t);
			}
		}
	}
	printf("%d", heap.top());
}