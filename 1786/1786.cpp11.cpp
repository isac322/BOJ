#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

const size_t &INF = numeric_limits<size_t>::max();

vector<size_t> failure;
vector<size_t> matched;

void initFailure(const string &pattern) {
	const size_t &len = pattern.size();

	failure.resize(len);
	fill(failure.begin(), failure.end(), 0);

	size_t index = 0;
	for (size_t i = 1; i < len; i++) {
		if (pattern[i] == pattern[index]) {
			failure[i] = ++index;
		}
		else if (index != 0) {
			index = failure[index - 1];

			i--;
		}
	}
}

vector<size_t> &KMP_all(const string &target, const string &pattern) {
	initFailure(pattern);
	matched.clear();

	const size_t &len = target.size(), &last = pattern.size();
	size_t index = 0;

	for (size_t i = 0; i < len; i++) {
		if (target[i] == pattern[index]) {
			index++;

			if (index == last) {
				matched.emplace_back(i - index + 1);

				index = failure.back();
			}
		}
		else if (index != 0) {
			index = failure[index - 1];

			i--;
		}
	}

	return matched;
}

int main() {
	string t, p;
	getline(cin, t);
	getline(cin, p);

	KMP_all(t, p);
	cout << matched.size() << '\n';
	for (auto d : matched) {
		cout << d + 1 << ' ';
	}
}