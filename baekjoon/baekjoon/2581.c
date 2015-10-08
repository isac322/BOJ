#include <stdio.h>

void main(void) {
	int start, end, sum = 0 ,min = 0 ;
	int i, j ;

	scanf("%d\n%d", &start, &end) ;
	for(i = start; i <= end; i++) {
		for(j = 2; j <= i; j++)
			if(i % j == 0)
				break ;
		if(j == i) {
			sum += i ;
			if(!min)
				min = i ;
		}
	}
	if(!min) {
		puts("-1") ;
		return ;
	}
	printf("%d\n%d", sum, min) ;
}