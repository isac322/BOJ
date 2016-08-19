#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

char str[200001];
int len = 0;
int main() {
	int n, top = 0, t;
	stack<int> st;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &t);

		if (top < t) {
			for (; top < t; top++) {
				str[len++] = '+';
				st.push(top + 1);
			}
		}
		else {
			if (st.top() != t) {
				puts("NO");
				return 0;
			}
		}
		st.pop();
		str[len++] = '-';
	}
	for (int i = 0; i < len; i++) printf("%c\n", str[i]);
}