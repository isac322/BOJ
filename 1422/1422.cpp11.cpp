#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp1(const string &l, const string &r) {
	auto i = l.begin(), j = r.begin();

	while (i != l.end() && j != r.end()) {
		if (*i < *j) return false;
		else if (*i > *j) return true;
		i++, j++;
	}

	if (l.length() == r.length()) return false;
	else if (i != l.end()) {
		string tmp(i, l.end());
		tmp += r;
		return cmp1(tmp, l);
	}
	else {
		string tmp(j, r.end());
		tmp += l;
		return cmp1(r, tmp);
	}
}

bool cmp(const string &l, const string &r) {
	if (l.length() == r.length()) return l.compare(r) == 1;
	else return l.length() > r.length();
}

int main() {
	int n, k;
	scanf("%d %d\n", &n, &k);
	vector<string> arr(n);
	for (int i = 0; i < n; i++) getline(cin, arr[i]);
	if (n == k) {
		sort(arr.begin(), arr.end(), cmp1);
		for (const auto &t : arr) printf("%s", t.c_str());
	}
	else {
		sort(arr.begin(), arr.end(), cmp);
		for (int i = 0; i < k - n; i++) arr.emplace_back(arr[0]);
		sort(arr.begin(), arr.end(), cmp1);
		for (const auto &t : arr) printf("%s", t.c_str());
	}
}