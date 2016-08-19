#include <stdio.h>

int main(void) {
	int num, checkNm, cnt = 0 ;
	int i, j ;

	scanf("%d",&num) ;
	for(i = 0; i < num; i++) {
		scanf("%d", &checkNm) ;
		for(j = 2; j <= checkNm; j++)
			if(checkNm % j == 0)
				break ;
		if(checkNm == j)
			cnt++ ;
	}
	printf("%d", cnt) ;
}