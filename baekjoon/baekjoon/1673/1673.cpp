#include <cstdio>

using namespace std;

int main() {
	unsigned long long n, k;
	while (~scanf("%llu%llu", &n, &k)) {
		unsigned long long tmp = n;
		while (tmp / k) {
			n += tmp / k;
			tmp = tmp / k + tmp%k;
		}
		printf("%llu\n", n);
	}
}