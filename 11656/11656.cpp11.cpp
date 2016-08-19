#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const size_t MAX = 256;
size_t n, S;
vector<size_t> result, group, cnt, tmp;

auto getGroup = [&](size_t t) -> size_t { return group[min(n, t)]; };

inline void bucketSort(const size_t start, const size_t last, const size_t t) {
	size_t m = 1;
	for (m = 1; m < S && cnt[m - 1] != last - start; m++) cnt[m] += cnt[m - 1];

	for (size_t i = start; i < last; i++) tmp[i] = result[i];
	for (size_t i = start; i < last; i++) result[--cnt[getGroup(tmp[i] + t)] + start] = tmp[i];

	tmp[result[start]] = start + 1;
	for (size_t i = start + 1; i < last; i++) {
		tmp[result[i]] = getGroup(result[i - 1] + t) != getGroup(result[i] + t) ? i + 1 : tmp[result[i - 1]];
	}
	for (size_t i = start; i < last; i++) group[result[i]] = tmp[result[i]];

	fill_n(cnt.begin(), m, 0);
}

vector<size_t> &suffixArray(const string &str) {
	n = str.size();
	result.resize(n);
	group.resize(n);
	tmp.resize(n);
	S = max(MAX, n + 1);
	cnt.resize(S);
	fill(cnt.begin(), cnt.end(), 0);

	for (size_t i = 0; i < n; i++) cnt[group[i] = size_t(str[i])]++;
	for (size_t i = 1; i < S && cnt[i - 1] != n; i++) cnt[i] += cnt[i - 1];
	for (size_t i = 0; i < n; i++) result[--cnt[group[i]]] = i;
	group[result[0]] = 1;
	for (size_t i = 1; i < n; i++) group[result[i]] = str[result[i]] == str[result[i - 1]] ? group[result[i - 1]] : i + 1;
	fill(cnt.begin(), cnt.end(), 0);
	group.emplace_back(0);
	tmp.emplace_back(0);

	for (size_t t = 1; t < n; t *= 2) {
		size_t prev = 0;
		for (size_t here = 0; here < n; here++) {
			if (group[result[prev]] != group[result[here]]) {
				bucketSort(prev, here, t);
				prev = here;
			}
			cnt[getGroup(result[here] + t)]++;
		}

		bucketSort(prev, n, t);
	}

	return result;
}

int main() {
	string t;
	getline(cin, t);
	for (auto p : suffixArray(t)) cout << t.c_str() + p << '\n';
}