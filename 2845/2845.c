#include <stdio.h>
main(){
	int a,b,i,c[5];
	scanf("%d%d",&a,&b);
	a*=b;
	for(i=0;i<5;i++){
		scanf("%d",&b);
		c[i]=b-a;
	}
	for(i=0;i<5;i++)
		printf("%d ",c[i]);
}