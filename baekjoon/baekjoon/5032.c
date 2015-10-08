#include <stdio.h>
main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	a+=b;
	for(b=0;a>=c;a++,b++)
		a-=c;
	printf("%d",b);
}