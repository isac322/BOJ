#include <cstdio>

using namespace std;

int main() {
	char c;
	long long sum = 0;
	int num = 0;
	while ((c = getchar()) != -1) {
		switch (c) {
			case '\n':
				continue;
			case ',':
				sum += num;
				num = 0;
				break;
			default:
				num *= 10;
				num += c - '0';
				break;
		}
	}
	printf("%lld", sum + num);
}