#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b ;
}

void main(void) {
	int num[5] = {0}, sum = 0 ;
	int i ;

	for(i = 0; i < 5; i++) {
		scanf("%d", &num[i]) ;
		sum += num[i] ;
	}

	qsort(num, 5, sizeof(int), cmp) ;

	printf("%d\n%d", sum / 5, num[2]) ;
}