#include <cstdio>
#include <deque>

using namespace std;

int main() {
	int n, m;
	deque<int> st;

	scanf("%d %d", &n, &m);
	for (int i = m + 1; i <= n; i++) st.push_back(i);
	for (int i = 1; i < m; i++) st.push_back(i);

	printf("<%d", m);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			st.push_back(st.front());
			st.pop_front();
		}

		printf(", %d", st.front());
		st.pop_front();
	}
	putchar('>');
}