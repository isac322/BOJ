#include <stdio.h>
#include <string.h>

int main() {
	char a[1000] = {0};
	int Tcase;

	scanf("%d", &Tcase);
	getchar();

	while(Tcase--) {
		gets(a);
		puts(a[strlen(a)/2] == a[strlen(a)/2 - 1] ? "Do-it" : "Do-it-Not");
	}
}