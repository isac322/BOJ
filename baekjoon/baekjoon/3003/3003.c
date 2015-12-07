#include <stdio.h>
main(){
	int a[]={1,1,2,2,2,8},b[6]={0},i;
	for(i=0;i<6;i++){
		scanf("%d",&b[i]);
		printf("%d ",a[i]-b[i]);
	}
}