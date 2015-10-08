#include <stdio.h>

int main() {
	int year;

	scanf("%d", &year);
	for (; year > 60; year -= 60);
	year-=4;
	printf("%c%d", 'A' + year % 12, year % 10);
}