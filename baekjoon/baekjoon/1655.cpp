#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

#define M 20090711LL

using namespace std;

int main() {
	int n;

	vector<int> low_heap, high_heap;
	scanf("%d", &n);

	int middle;
	scanf("%d", &middle);
	printf("%d\n", middle);

	for (int i = 1; i < n; i++) {
		int next;
		scanf("%d", &next);

		if (next > middle) {
			high_heap.push_back(next);
			push_heap(high_heap.begin(), high_heap.end(), greater<int>());
		}
		else {
			low_heap.push_back(next);
			push_heap(low_heap.begin(), low_heap.end());
		}

		int index = i >> 1;

		if (low_heap.size() > index) {
			high_heap.push_back(middle);
			push_heap(high_heap.begin(), high_heap.end(), greater<int>());

			pop_heap(low_heap.begin(), low_heap.end());
			middle = low_heap.back();
			low_heap.pop_back();
		}
		else if (low_heap.size() < index) {
			low_heap.push_back(middle);
			push_heap(low_heap.begin(), low_heap.end());

			pop_heap(high_heap.begin(), high_heap.end(), greater<int>());
			middle = high_heap.back();
			high_heap.pop_back();
		}

		printf("%d\n", middle);
	}
}