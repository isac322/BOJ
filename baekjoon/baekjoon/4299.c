#include <stdio.h>
main(){
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=(a+b);
	if(c/2>a||(a+b)%2)puts("-1");
	else printf("%d %d",c/2,a-c/2);
}