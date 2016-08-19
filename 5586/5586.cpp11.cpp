#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

namespace BoyerMoore {
	unordered_map<char, size_t> map;
	vector<size_t> mached;

	void init_map(const string &pattern) {
		map.clear();

		for (size_t i = 0; i < pattern.size(); i++) {
			map[pattern[i]] = i;
		}
	}

	vector<size_t>& boyer_moore_all(const string &target, const string &pattern) {
		init_map(pattern);
		mached.clear();

		const size_t &t_len = target.size(), &p_len = pattern.size();
		size_t index = p_len;

		bool check;

		while (true) {
			check = true;

			for (size_t i = 1; i <= p_len; i++) {
				if (target[index - i] != pattern[p_len - i]) {
					check = false;
					break;
				}
			}

			if (check) {
				mached.push_back(index - p_len);

				index += p_len - map[target[index]];
			}
			else if (index >= t_len) {
				return mached;
			}
			else {
				index += p_len - map[target[index]];
			}
		}
	}
}

using namespace BoyerMoore;

char str[10000];

int main() {
	gets(str);

	printf("%zd\n%zd", boyer_moore_all(str, "JOI").size(), boyer_moore_all(str, "IOI").size());
}