#include <cstdio>
#include <vector>

using namespace std;

long long arr[1000000] = { 0 };
long long change[1000000] = { 0 };
int val[1000000] = { 0 };
vector<int> v;

int main() {
	int n, m, k, i, j, a, b, c, t, len;
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d", val);
	arr[0] = val[0];
	for (i = 1; i < n; i++) {
		scanf("%d", val + i);
		arr[i] = arr[i - 1] + val[i];
	}
	long long re;
	for (i = 0; i < m + k; i++) {
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		if (a) {
            c--;
			if (!b) re = arr[c];
			else re = arr[c] - arr[b - 1];
			len = v.size();
			for (j = 0; j < len; j++) {
				t = v[j];
				if (t >= b && t <= c) re += change[t];
			}
			printf("%lld\n", re);
		} else {
			if (!change[b]) v.push_back(b);
			change[b] += c - val[b];
			val[b] = c;
		}
	}
}