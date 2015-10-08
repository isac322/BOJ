#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	stack<int> st;
	char str[9];
	while (n--) {
		scanf("%s", str);

		switch (str[0]) {
			case 'p':
				if (str[1] == 'u') {
					int t;
					scanf("%d", &t);
					st.push(t);
				}
				else {
					if (st.empty()) puts("-1");
					else {
						printf("%d\n", st.top());
						st.pop();
					}
				}
				break;
			case 's':
				printf("%d\n", st.size());
				break;
			case 'e':
				puts(st.empty() ? "1" : "0");
				break;
			case 't':
				if (st.empty()) puts("-1");
				else printf("%d\n", st.top());
		}
	}
}