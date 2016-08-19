#include <stdio.h>
main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++)
			putchar(32);
		for(j=0;j<i*2+1;j++)
			putchar('*');
		putchar(10);
	}
}