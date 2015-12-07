#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <tr1/unordered_map>
#include <algorithm>

using namespace std;
using namespace std::tr1;

int main() {
	int c;
	scanf("%d\n", &c);

	char tmp[101];
	while (c--) {
		unordered_map<string, bool> map;
		vector<string> arr;

		do {
			string t;
			cin >> t;
			arr.push_back(t);
		} while (getchar() != '\n');

		while (true) {
			scanf("%s %s ", tmp, tmp);
			if (tmp[0] == 'd') {
				gets(tmp);

				break;
			}

			string t;
			cin >> t;
			getchar();

			map[t] = true;
		}

		for (size_t i = 0; i < arr.size(); i++) {
			if (!map[arr[i]]) cout << arr[i] << ' ';
		}
		puts("");
	}
}