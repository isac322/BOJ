#include <stdio.h>

void main(void) {
	int Apnt = 0, Bpnt = 0, BCard, ADeck[11] = {0}, result[11] = {0} ;
	int i ;

	for(i = 0; i < 10; i++)
		scanf("%d", &ADeck[i]) ;
	for(i = 0; i < 10; i++) {
		scanf("%d", &BCard) ;
		if(ADeck[i] == BCard) {
			result[i] = 'D' ;
			Apnt++ ;
			Bpnt++ ;
		} else if(ADeck[i] > BCard) {
			result[i] = 'A' ;
			Apnt += 3 ;
		} else {
			result[i] = 'B' ;
			Bpnt += 3 ;
		}
	}
	printf("%d %d\n", Apnt, Bpnt) ;
	if(Apnt == Bpnt) {
		for(i = 9; result[i] == 'D'; i--) ;
		if(i == -1)
			putchar('D') ;
		else
			putchar(result[i]) ;
	} else
		printf("%c", Apnt > Bpnt ? 'A' : 'B') ;
}