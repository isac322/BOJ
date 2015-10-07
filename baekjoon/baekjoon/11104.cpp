#include <cstdio>
#include <bitset>

using namespace std;

int main() {
	int t;
	scanf("%d\n", &t);
	char str[25];
	while (t--) {
		gets(str);
		bitset<24> set(str);
		printf("%u\n", set.to_ulong());
	}
}