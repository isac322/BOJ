#include <stdio.h>
main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=n;i>0;i--){
		for(j=0;j<n-i;j++)
			putchar(32);
		for(j=0;j<i*2-1;j++)
			putchar('*');
		putchar(10);
	}
}