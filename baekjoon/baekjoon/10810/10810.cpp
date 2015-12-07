#include <iostream>

using namespace std;

int main() {
	int arr[101] = {0};
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		for (int j = a; j <= b; ++j) arr[j] = c;
	}
	for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
}