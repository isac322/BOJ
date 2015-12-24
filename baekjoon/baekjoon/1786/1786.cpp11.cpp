#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> failure;
vector<size_t> mached;

void buildTable(string &w) {
	failure.resize(w.size());

	int i = 2, j = 0;
	failure[0] = -1;
	failure[1] = 0;

	while (i < w.length()) {
		if (w[i - 1] == w[j]) {
			failure[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0) j = failure[j];
		else {
			failure[i] = 0;
			i++;
		}
	}
}

void KMP(string &s, string &w) {
	int m = 0, i = 0;

	buildTable(w);
	while (m + i < s.length()) {
		if (w[i] == s[m + i]) {
			i++;
			if (i == w.length()) {
				mached.emplace_back(m);

				i--;
				m += i - failure[i];
				i = failure[i];
			}
		}
		else {
			m += i - failure[i];
			if (i > 0) i = failure[i];
		}
	}
}


int main() {
	string t, p;
	getline(cin, t);
	getline(cin, p);

	KMP(t, p);
	cout << mached.size() << '\n';
	for (auto d : mached) {
		cout << d + 1 << ' ';
	}
}