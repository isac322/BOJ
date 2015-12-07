#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int r, c, zr, zc;
	char t;
	string str;
	scanf("%d %d %d %d\n", &r, &c, &zr, &zc);
	for (int i = 0; i < r; i++) {
		str.clear();
		for (int j = 0; j < c; j++) {
			t = getchar();
			for (int l = 0; l < zc; l++) str.push_back(t);
		}
		for (int j = 0; j < zr; j++) puts(str.c_str());
		getchar();
	}
}