#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int num1 ;
	int i ;
	char num2[4] = {0} ;

	scanf("%d\n%s", &num1, num2) ;
	
	for(i = 2; i >= 0; i--)
		printf("%d\n", num1 * (num2[i] - '0')) ;
	printf("%d", num1 * atoi(num2)) ;
}