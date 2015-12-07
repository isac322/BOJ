#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str[10], cmp;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) cin >> str[i];

	bool re = true;
	for (int i = 0; i < n; i++) {
		cin >> cmp;

		bool check = true;
		if (cmp.size() == (str[i].size() << 1)) {
			for (int j = 0; j < cmp.size(); j++) {
				if (str[i][j >> 1] != cmp[j]) {
					check = false;
					break;
				}
			}
		}
		else check = false;

		re &= check;
	}
	puts(re ? "Eyfa" : "Not Eyfa");
}