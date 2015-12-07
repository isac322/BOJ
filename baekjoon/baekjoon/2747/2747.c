#include <stdio.h>

int main(void) {
	int num ;
	int pibo[45] = {0,1,1,0} ;
	int i ;
	scanf("%d",&num) ;
	for(i = 3; i <= num; i++)
		pibo[i] = pibo[i - 1] + pibo[i - 2] ;
	printf("%d",pibo[num]) ;
}