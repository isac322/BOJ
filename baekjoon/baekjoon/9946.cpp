#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string str1, str2;
	int t = 1;
	while (true) {
		getline(cin, str1);
		getline(cin, str2);

		if (str1 == "END" && str2 == "END") break;

		int cnt1[26] = { 0 }, cnt2[26] = { 0 };
		for (int i = 0; str1[i]; i++) cnt1[str1[i] - 'a']++;
		for (int i = 0; str2[i]; i++) cnt2[str2[i] - 'a']++;

		bool check = true;
		for (int i = 0; i < 26; i++) if (cnt1[i] != cnt2[i]) check = false;

		printf("Case %d: %s\n", t, check ? "same" : "different");
		t++;
	}
}