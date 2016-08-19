#include <stdio.h>
main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n*2-1;i++){
		if(i<n){
			for(j=0;j<=i;j++)
				putchar('*');
			for(j=0;j<(n-i)*2-2;j++)
				putchar(32);
			for(j=0;j<=i;j++)
				putchar('*');
		}else{
			for(j=2*(n-1)-i;j>=0;j--)
				putchar('*');
			for(j=0;j<(i-n)*2+2;j++)
				putchar(32);
			for(j=2*(n-1)-i;j>=0;j--)
				putchar('*');
		}
		putchar(10);
	}
}