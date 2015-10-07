#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

#define SKIP 2
#define BOTH 1
#define NONE 0

using namespace std;

#define M 1000000

string str;
vector<int> dp;
int len;

int solve(int idx) {
	if (idx == len) return 1;

	int &p = dp[idx];
	if (p != -1) return p;
	p = 0;

	int next;

	switch (str[idx]) {
		case '0':
			return 0;
		case '1':
			next = str[idx + 1] == '0' ? SKIP : BOTH;
			break;
		case '2':
			if (str[idx + 1] == '0') next = SKIP;
			else if (str[idx + 1] > '6') next = NONE;
			else next = BOTH;
			break;
		default:
			next = NONE;
	}

	switch (next) {
		case NONE:
			p = solve(idx + 1);
			break;
		case SKIP:
			if (idx < len - 1) p = solve(idx + 2);
			break;
		case BOTH:
			p = solve(idx + 1);
			if (idx < len - 1) p += solve(idx + 2);
	}

	return p % M;
}

int main() {
	getline(cin, str);
	len = str.length();
	dp.resize(len, -1);
	printf("%d\n", solve(0));
}