#include <cstdio>

int main() {
	int year;
	scanf("%d", &year);
	year += 56;
	printf("%c%d", 'A' + year % 12, year % 10);
}