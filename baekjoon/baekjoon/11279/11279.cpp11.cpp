#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> heap;
	int n, t;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		if (t == 0) {
			if (heap.empty()) puts("0");
			else {
				pop_heap(heap.begin(), heap.end());
				printf("%d\n", heap.back());
				heap.pop_back();
			}
		}
		else {
			heap.emplace_back(t);
			push_heap(heap.begin(), heap.end());
		}
	}
}