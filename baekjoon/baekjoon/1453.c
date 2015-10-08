#include <stdio.h>

int main(void) {
	int order, people, cnt = 0 ;
	int i ;
	char seat[100] = {0} ;

	scanf("%d", &people) ;
	for(i = 0; i < people; i++) {
		scanf("%d",&order) ;
		if(seat[order - 1])
			cnt++ ;
		else
			seat[order - 1]++ ;
	}
	printf("%d", cnt) ;
}