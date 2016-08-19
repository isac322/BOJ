#include <stdio.h>

int main(void) {
	int num ;
	int i, j ;
	int cnt = 0 ;
	char result[11] = {0} ;

	for(i = 0; i < 10; i++) {
		scanf("%d",&num) ;
		result[i] = num % 42 ;
	}

	for(i = 0; i < 42; i++) {
		for(j = 0; j < 10; j++) {
			if(result[j] == i) {
				cnt++ ;
				break ;
			}
		}
	}
	printf("%d", cnt) ;
}