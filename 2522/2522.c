#include <stdio.h>

main() {
	int a,i,j;

	scanf("%d",&a);
	for(i=1;i<=a;i++) {
		for(j=a;j>i;j--)
			putchar(32);
		for(j=0;j<i;j++)
			putchar('*');
		putchar(10);
	}
	for(i=a-1;i>0;i--) {
		for(j=0;j<a-i;j++)
			putchar(32);
		for(j=0;j<i;j++)
			putchar('*');
		putchar(10);
	}
}