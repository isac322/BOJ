#include <cstdio>

int main() {
    char a, b[10]="", m=0;
	for (int i = 0; ~scanf("%c", &a); i++) b[a - '0']++;
	b[6] += b[9];
	b[9] = b[6] / 2 + (b[6] & 1);
	b[6] /= 2;
    for (char v : b) if (v > m) m = v;
	printf("%d", m);
}