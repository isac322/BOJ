#include <stdio.h>

void main(void) {
	int i ;
	int num, max = 0, loc ;

	for(i = 0; i < 9; i++) {
		scanf("%d",&num) ;
		if(num > max) {
			max = num ;
			loc = i ;
		}
	}
	
	printf("%d\n%d", max, loc + 1) ;
}