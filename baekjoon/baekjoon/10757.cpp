#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	char t;
	vector<char> s1, s2;
	while ((t = getchar()) != ' ') {
		s1.push_back(t - '0');
	}
	while ((t = getchar()) != '\n') {
		s2.push_back(t - '0');
	}
	vector<char> re;

	int c = 0;
	while (!s1.empty() || !s2.empty()) {
		if (s1.empty()) {
			char t = s2.back() + c;
			re.push_back(t % 10);
			c = t / 10;
			s2.pop_back();
		}
		else if (s2.empty()) {
			char t = s1.back() + c;
			re.push_back(t % 10);
			c = t / 10;
			s1.pop_back();
		}
		else {
			char t = s1.back() + s2.back() + c;
			re.push_back(t % 10);
			c = t / 10;
			s1.pop_back();
			s2.pop_back();
		}
	}
	if (c) re.push_back(c);

	for (vector<char>::reverse_iterator i = re.rbegin(); i != re.rend(); i++) {
		printf("%d", *i);
	}
}