#include <stdio.h>

void main(void) {
	int num, cnt = 0 ;
	int i ;

	scanf("%d %d", &num, &cnt) ;
	for(i = 1; cnt; i++) {
		if(i > num) {
			puts("0") ;
			return ;
		}
		if(num % i == 0)
			cnt--;
	}
	printf("%d", i - 1) ;
}