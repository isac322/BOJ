#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using namespace std;
map<string, char> mat;

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);

	string a;
	for (int i = 0; i < n; i++) {
		getline(cin, a);

		mat[a] = 1;
	}

	for (int i = 0; i < m; i++) {
		getline(cin, a);

		if (mat[a] == 1) mat[a] = 2;
	}

	int count = 0;
	for (map<string, char>::iterator i = mat.begin(); i != mat.end(); i++) {
		if (i->second == 2) count++;
	}

	cout << count << '\n';
	for (map<string, char>::iterator i = mat.begin(); i != mat.end(); i++) {
		if (i->second == 2) cout << i->first << '\n';
	}
}