#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stack>

using namespace std;

string str;

bool check() {
	const size_t &len = str.size();
	stack<char> st;

	for (size_t i = 0; i < len; i++) {
		const char &ch = str[i];

		if (ch == '(' || ch == '{' || ch == '[') st.push(ch);
		else if (ch == ')') {
			if (st.size() == 0 || st.top() != '(') return false;
			else st.pop();
		}
		else {
			if (st.size() == 0 || st.top() != ch - 2) return false;
			else st.pop();
		}
	}

	return st.size() == 0 ? true : false;
}

pair<int, int> calc(int start) {
	const char &ch = str[start], &next = str[start + 1];

	pair<int, int> ret(0, 0);
	if (ch == '(') {
		if (next == ')') {
			ret.first = 2;
			ret.second = 2;
		}
		else {
			const pair<int, int> &p = calc(start + 1);
			ret.first = 2 * p.first;
			ret.second = p.second + 2;
		}
	}
	else {
		if (next == ']') {
			ret.first = 3;
			ret.second = 2;
		}
		else {
			const pair<int, int> &p = calc(start + 1);
			ret.first = 3 * p.first;
			ret.second = p.second + 2;
		}
	}

	while (true) {
		int index = ret.second + start;
		if (index >= str.size() || str[index] == ')' || str[index] == ']') break;
		const pair<int, int> &p = calc(index);

		ret.first += p.first;
		ret.second += p.second;
	}

	return ret;
}

int main() {
	getline(cin, str);
	if (!check()) {
		puts("0");
		return 0;
	}

	printf("%d", calc(0).first);
}