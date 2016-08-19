#include <stdio.h>
main(){
	int n,i,C=1;
	scanf("%d",&n);
	for(i=1;i<=4;i++)
		C=C*(n-i+1)/i;
	printf("%d",C);
}