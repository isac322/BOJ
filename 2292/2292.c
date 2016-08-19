#include <stdio.h>
main(){
	int n,i,s;
	scanf("%d",&n);
	for(i=1,n--;n>0;i++)
		n-=i*6;
	printf("%d",i);
}