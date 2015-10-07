#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> arr;
	while (true) {
		int n;
		scanf("%d", &n);
		if (n == -1) break;

		arr.clear();
		arr.push_back(1);
		for (int i = 2; i < n; i++) if (n % i == 0) arr.push_back(i);
		int sum = 0;
		for (int i = 0; i < arr.size(); i++) sum += arr[i];
		if (sum == n) {
			printf("%d = 1 ", n);
			for (int i = 1; i < arr.size(); i++) printf("+ %d ", arr[i]);
		}
		else {
			printf("%d is NOT perfect.", n);
		}
		puts("");
	}
}