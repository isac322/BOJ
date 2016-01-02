#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

map<long long, long long> m;

long long n, p, q;

long long solve(long long num) {
	if (m.find(num) != m.end()) return m[num];
	return m[num] = solve(num / p) + solve(num / q);
}

int main() {
	m[0] = 1;
	scanf("%lld %lld %lld", &n, &p, &q);
	printf("%lld", solve(n));
}