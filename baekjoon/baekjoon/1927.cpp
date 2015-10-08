#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main() {
	priority_queue< int, vector<int>, greater<int> > heap;
	int n, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (!a) {
			if (!heap.empty()) {
				printf("%d\n", heap.top());
				heap.pop();
			} else {
				puts("0");
			}
		}
		else {
			heap.push(a);
		}
	}
}