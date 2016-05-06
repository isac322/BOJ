#include <cstdio>

int main() {
	char ch;
	int state = 0, a = 0, b = 0;
	while ((ch = getchar()) != 10 && ch != -1) {
		switch (state) {
			case 0:
				if (ch == ':') state = 1;
				break;
			case 1:
				if (ch == '-') state = 2;
				break;
			case 2:
				if (ch == '(') a++;
				else if (ch == ')') b++;
				state = 0;
		}
	}
	if (a == b) puts(a ? "unsure" : "none");
	else puts(a < b ? "happy" : "sad");
}