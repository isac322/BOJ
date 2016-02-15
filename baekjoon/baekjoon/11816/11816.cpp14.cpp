#include <cstdio>
#include <string>

using namespace std;

char a[21];
int main() {
	scanf("%s", a);
	if (a[0] == '0' && a[1] == 'x') printf("%d", stoi(a, nullptr, 16));
	else if (a[0] == '0' && a[1]) printf("%d", stoi(a, nullptr, 8));
	else printf("%d", stoi(a, nullptr, 10));
}