#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int sum = 0;
	while (n--) {
		int a, b;
		cin >> a >> b;
		int dif = b >= a ? b - a : b;
		for (int i = 2; a * i <= b; i++) {
			dif = min(dif, b - a * i);
		}
		sum += dif;
	}
	cout << sum;
}