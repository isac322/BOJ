#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	int n;
	scanf("%d\n", &n);

	vector<string> arr;
	for (int i = 0; i < n; i++) {
		string tmp;
		getline(cin, tmp);

		bool check = true;
		for (int j = 0; j < 9; j++) {
			if (str[j] != '*' && str[j] != tmp[j]) check = false;
		}

		if (check) arr.push_back(tmp);
	}

	printf("%d\n", arr.size());
	for (size_t i = 0; i < arr.size(); i++) {
		cout << arr[i] << '\n';
	}
}