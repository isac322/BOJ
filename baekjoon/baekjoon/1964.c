#include <stdio.h>

int main() {
	int max = 0, pnt = 5 ;
	int i = 1 ;

	scanf("%d", &max) ;

	for(; i < max; i++) {
		pnt += 3 * i + 4 ;
		pnt %= 45678 ;
	}

	printf("%d", pnt) ;
}