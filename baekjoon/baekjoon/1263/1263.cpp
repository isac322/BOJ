#include <cstdio>
#include <algorithm>

using namespace std;

struct Task {
	int ti, si;

	inline bool operator<(const Task &val) const {
		return si > val.si;
	}
}tasks[1000];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d %d", &tasks[i].ti, &tasks[i].si);
	sort(tasks, tasks + n);

	int start = tasks[0].si;
	for (int i = 0; i < n; i++) {
		if (start > tasks[i].si) {
			start = tasks[i].si;
		}

		start -= tasks[i].ti;
	}

	printf("%d", start < 0 ? -1 : start);
}