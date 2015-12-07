#include <stdio.h>

void main(void) {
	int num[3] = {0}, result ;
	int i ;
	char chNum[11] = {0}, Nnum[10] = {0} ;

	for(i = 0, result = 1; i < 3; i++) {
		scanf("%d", &num[i]) ;
		result *= num[i] ;
	}

	sprintf(chNum, "%d", result) ;

	for(i = 0; chNum[i]; i++)
		Nnum[chNum[i] - '0']++ ;

	for(i = 0; i < 10; i++)
		printf("%d\n", Nnum[i]) ;
}