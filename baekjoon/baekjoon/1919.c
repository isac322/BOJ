#include <stdio.h>
#include <string.h>
main(){
	char a[26]={0},b[26]={0},d[1001];
	int i,j=0;
	scanf("%s",d);
	for(i=0;i<strlen(d);i++)
		a[d[i]-97]++;
	scanf("%s",d);
	for(i=0;i<strlen(d);i++)
		b[d[i]-97]++;
	for(i=0;i<26;i++)
		if(a[i]!=b[i])
			j+=a[i]>b[i]?a[i]-b[i]:b[i]-a[i];
	printf("%d",j);
}