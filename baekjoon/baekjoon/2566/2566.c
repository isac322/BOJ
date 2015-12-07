#include <stdio.h>

void main(void) {
	int num, max = 0 ;
	int i = 0, loc ;
	for(; ~scanf("%d",&num); i++) {
		if(num > max) {
			max = num ;
			loc = i ;
		}
	}
	
	printf("%d\n%d %d", max, (loc / 9) + 1, (loc % 9) + 1) ;
}