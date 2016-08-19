#include <stdio.h>
#include <string.h>
main(){
	int a,b,i,j;
	char c[21];
	scanf("%d",&a);
	while(a--){
		scanf("%d %s",&b,c);
		for(i=0;i<strlen(c);i++)
			for(j=0;j<b;j++)
				putchar(c[i]);
		putchar(10);
	}
}