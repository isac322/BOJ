#include <stdio.h>
#include <string.h>
main(){
	char a[1000000]={0};
	int i,j=1;
	gets(a);
	for(i=0;i<strlen(a)-1;i++)
		if(a[i]==32&&a[i+1]>64)
			j++;
	if(a[0]==32)
		j--;
	printf("%d",j);
}