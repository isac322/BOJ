#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
main(){
	int a[9]={0},i=0,j=0,s=0,d;
	for(;i<9;s+=a[i++])
		scanf("%d",&a[i]);
	d=s-100;
	qsort(a,9,sizeof(int),cmp);
	for(i=0;i<9;i++){
		for(j=i+1;j<9;j++)
			if(d==(a[i]+a[j])){
				for(s=0;s<9;s++){
					if(s==i||s==j) continue;
					printf("%d\n",a[s]);
				}
				return;
			}
	}
}