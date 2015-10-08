#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)b - *(int *)a ;
}

int main(void) {
	int point[8], temp[8] ;
	int i, j ;
	int sum = 0 ;
	for(i = 0; i < 8; i++) {
		scanf("%d", &point[i]) ;
		temp[i] = point[i] ;
	}
	qsort(temp,8,sizeof(int),cmp) ;

	for(i = 0; i < 5; i++)
		sum += temp[i] ;
	printf("%d\n", sum) ;
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 5; j++) {
			if(point[i] == temp[j]) {
				printf("%d ", i + 1) ;
				break ;
			}
		}
	}
}