#include <stdio.h>

void main(void) {
	int num[10] = {0}, sum = 0, max = 0 ;
	int i ;
	char check[100] = {0} ;
	
	for(i = 0; i < 10; i++) {
		scanf("%d", &num[i]) ;
		sum += num[i] ;
		check[num[i] / 10 - 1]++ ;
	}

	for(i = 0; i < 100; i++)
		if(check[i] > max)
			max = i ;

	printf("%d\n%d", sum / 10, (max + 1) * 10) ;
}