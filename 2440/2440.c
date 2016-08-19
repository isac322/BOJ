#include <stdio.h>
main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=n;i>0;i--){
		for(j=0;j<i;j++)
			putchar('*');
		putchar(10);
	}
}