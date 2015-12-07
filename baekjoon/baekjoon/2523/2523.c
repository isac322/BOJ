#include <stdio.h>

void main(void) {
	int num ;
	int i, j ;

	scanf("%d", &num) ;

	for(i = 1; i <= num * 2  - 1; i++) {
		if(i > num)
			for(j = 0; j < num * 2 - i; j++)
				putchar('*') ;
		else
			for(j = 0; j < i; j++)
				putchar('*') ;
		putchar(10) ;
	}
}