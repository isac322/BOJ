#include <stdio.h>

void main(void) {
	int num, cnt = 1, sum = 0, max ;
	int i ;

	scanf("%d", &max) ;
	for(i = 0; i < max; i++) {
		scanf("%d", &num) ;
		if(!num)
			cnt = 0 ;
		else {
			if(!cnt)
				cnt++ ;
			sum += cnt++ ;
		}
	}
	printf("%d", sum) ;
}