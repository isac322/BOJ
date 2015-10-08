#include <iostream>
using namespace std;

int main() {
	char b = 1, *p, e[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", u[27] = { 0 }, t[27], y[27], a[27];
	int r, l, i, j, k = 0;

	cin >> l >> r >> u;
	p = e;
	for (i = 0; i < 26; i++) t[i] = i;
	for (i = 0; i < r; i++) {
		for (j = 0; j < l - 1; j++) {
			cin >> b;
			if (b == '-') swap(p[j], p[j + 1]);
			else if (b == '?') {
				p = t;
				cin >> y;
				break;
			}
		}
	}

	for (i = 0; i < l; i++) a[t[i]] = u[i];

	for (i = 0; i < l - 1; i++) {
		if (e[i] == a[i]) y[i] = '*';
		else if (e[i] == a[i + 1] && e[i + 1] == a[i]) {
			y[i] = '-';
			y[i + 1] = '*';
			i++;
		} else {
			for (j = 0; j < l - 1; j++) cout << 'x';
			return 0;
		}
	}
	y[l - 1] = 0;
	cout << y;
}