#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main(){
	int max,min;
	char *p,a[8]={0},b[8]={0};
	scanf("%s%s",a,b);
	while((p=strchr(a,'5')))
		*p='6';
	while((p=strchr(b,'5')))
		*p='6';
	max=atoi(a)+atoi(b);
	while((p=strchr(a,'6')))
		*p='5';
	while((p=strchr(b,'6')))
		*p='5';
	min=atoi(a)+atoi(b);
	printf("%d %d",min,max);
}