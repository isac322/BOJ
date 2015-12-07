#include <cstdio>

using namespace std;

int main() {
	long long sum = 0;
	int n, s[1000] = {0};
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		int t;
		
		for (int j = 0; j < n; ++j) {
			scanf("%d", &t);
			s[i] += t;
		}
		sum += s[i];
	}
	
	sum /= (n - 1) << 1;
	
	if (n == 2) {
		printf("1 %d", s[0] - 1);
	} else {
		for (int i = 0; i < n; ++i) {
			printf("%lld ", (s[i] - sum) / (n - 2));
		}
	}
}