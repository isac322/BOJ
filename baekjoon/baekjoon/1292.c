#include <stdio.h>
main(){
	int i,j,a,b;
	scanf("%d %d",&i,&j);
	for(a=1;i>0;a++)
		i-=a;
	for(b=1;j>0;b++)
		j-=b;
	i*=-1;
	i++;
	j*=-1;
	a-=1;
	b-=1;
	printf("%d",(b*(b+1)*(2*b+1))/6-(a*(a+1)*(2*a+1))/6+i*a-j*b);
}