#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}
char sum(char*);
main(){
	char a[64]={0},i=0;
	int max;
	scanf("%d",&max);
	a[0]=64;
	while(1){
		if(sum(a)==max)
			break;
		else if(sum(a)<max){
			puts("-1");
			return;
		}
		else{
			qsort(a,i+1,sizeof(char),cmp);
			a[i]/=2;
			if(sum(a)<max){
				a[i+1]=a[i];
				i++;
			}
		}
	}
	printf("%d",i+1);
}
char sum(char *a){
	int i=0,sum=0;
	for(;a[i];sum+=a[i++]);
	return sum;
}