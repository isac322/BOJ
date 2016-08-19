#include <cstdio>
#include <stack>

using namespace std;

int main() {
	int n, cnt = 0;
	char t;
	scanf("%d\n", &n);

	while (n--) {
		stack<char> st;

		while ((t = getchar()) != 10 && t != -1) {
			if (!st.empty() && st.top() == t) st.pop();
			else st.emplace(t);
		}
		if (st.empty()) cnt++;
	}
	printf("%d", cnt);
}