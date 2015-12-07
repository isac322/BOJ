#include <stdio.h>
#include <stdlib.h>
#define _swap(x,y,z) {z=x;x=y;y=z;}
main(){
	char a[4],b[4],c;
	scanf("%s %s",a,b);
	_swap(a[0],a[2],c);
	_swap(b[0],b[2],c);
	printf("%s",atoi(a)>atoi(b)?a:b);
}