#include <stdio.h>
#include <memory.h>
#include <malloc.h>
main(){
	int max,temp,*p,i;
	scanf("%d",&max);
	p=(int*)malloc(sizeof(int)*max);
	for(i=0;i<max;i++)
		scanf("%d",&p[i]);
	if((p[1]-p[0])==(p[2]-p[1])){
		temp=p[1]-p[0];
		printf("%d",p[max-1]+temp);
	}else{
		temp=p[1]/p[0];
		printf("%d",p[max-1]*temp);
	}
}