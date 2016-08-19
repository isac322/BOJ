#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> fib[10001];

void normalize(vector<char> &num) {
	num.push_back(0);
	for (int i = 0; i < num.size(); i++) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		} else if (num[i] > 0) {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	if (num.back() == 0) num.pop_back();
}

void addTo(vector<char> &a, vector<char> &b) {
	a.resize(max(a.size(), b.size()));

	int length = a.size();
	for (int i = 0; i < length; i++) a[i] += b[i];
}

int main() {
	int n;

	fib[0].push_back(1);
	fib[1].push_back(1);

	for (int i = 2; i < 10001; i++) {
		fib[i] = fib[i - 1];
		addTo(fib[i], fib[i - 2]);
		normalize(fib[i]);
	}

	while (~scanf("%d", &n)) {
		vector<char> ret(fib[n-2]);

		addTo(ret, fib[n]);
		normalize(ret);

		int length = ret.size();
		for (int i = length - 1; i >= 0; i--) {
			printf("%d", ret[i]);
		}
		puts("");
	}
}