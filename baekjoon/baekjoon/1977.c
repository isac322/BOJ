#include <stdio.h>
#include <math.h>

int main(void) {
	double start, end, sqrtNm ;
	double i ;
	int sum = 0, stat = 1, min = 0 ;

	scanf("%lf %lf",&start,&end);

	for(i = start; i <= end; i++) {
		sqrtNm = sqrt(i) ;
		if((int)sqrtNm == sqrtNm) {
			sum += i ;
			if(stat) {
				min = sum ;
				stat = 0 ;
			}
		}
	}
	if(!min) {
		puts("-1") ;
		return -1;
	} else
		printf("%d\n%d", sum, min) ;
}