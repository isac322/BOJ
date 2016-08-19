#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace SuffixArray_LCP {
	const size_t MAX = 256;
	size_t n, size;
	vector<size_t> sa, group, cnt, tmp, lcp;

	inline void countingSort(const vector<size_t> &highRadix, const size_t t) {
		size_t len = 1;
		for (size_t i = 0; i < n; i++) cnt[group[i]]++;
		for (; len < size && cnt[len - 1] != n; len++) cnt[len] += cnt[len - 1];

		for (auto iter = highRadix.rbegin() + 1; iter != highRadix.rend(); iter++) sa[--cnt[group[*iter]]] = *iter;
		fill_n(cnt.begin(), len, 0);

		auto &newGroup = tmp;
		newGroup[sa[0]] = 1;
		for (size_t i = 1, grp = 1; i < n; i++) {
			auto &prev = sa[i - 1], &now = sa[i];
			if (group[prev] != group[now] || group[prev] == group[now] && group[prev + t] != group[now + t]) grp++;
			newGroup[now] = grp;
		}
		swap(newGroup, group);
	}

	inline void radixSort(const vector<size_t> &lowRadix, const size_t t) {
		auto &highRadix = tmp;
		size_t p = 0;
		for (size_t i = n - t; i < n; i++) highRadix[p++] = i;
		for (size_t i = 0; i < n; i++) if (lowRadix[i] >= t) highRadix[p++] = lowRadix[i] - t;
		countingSort(highRadix, t);
	}

	vector<size_t> &suffixArray(const string &str) {
		n = str.size();
		sa.resize(n);

		group.resize(n);
		tmp.resize(n);
		group.emplace_back(0);
		tmp.emplace_back(0);

		size = max(MAX, n + 1);
		cnt.resize(size);
		fill(cnt.begin(), cnt.end(), 0);

		size_t len = 1;
		for (size_t i = 0; i < n; i++) cnt[group[i] = size_t(str[i])]++;
		for (; len < size && cnt[len - 1] != n; len++) cnt[len] += cnt[len - 1];
		for (size_t i = 0; i < n; i++) sa[--cnt[group[i]]] = i;
		fill_n(cnt.begin(), len, 0);

		for (size_t t = 1; t < n; t *= 2) radixSort(sa, t);

		return sa;
	}

	vector<size_t> &LCP(const string S, const vector<size_t> &SA) {
		const size_t n = SA.size();
		lcp.resize(n);
		auto &rank = tmp;

		for (size_t i = 0; i < n; i++) rank[SA[i]] = i;

		size_t k = 0;
		for (size_t i = 0; i < n; i++) {
			if (k) k--;
			if (rank[i] != 0) for (size_t j = SA[rank[i] - 1]; i + k < n && j + k < n && S[i + k] == S[j + k]; k++);
			else k = 0;
			lcp[rank[i]] = k;
		}

		return lcp;
	}

	vector<size_t> &LCP(const std::string S) {
		return LCP(S, suffixArray(S));
	}
}

int main() {
	char t[5001];
	size_t m = 0;
	for (auto p : SuffixArray_LCP::LCP(gets(t))) m = max(m, p);
	printf("%zd", m);
}