#include <stdio.h>
main(){
	int i,max=0,j,maxP,a,sum;
	for(i=1;i<6;i++){
		sum=0;
		for(j=0;j<4;j++){
			scanf("%d",&a);
			sum+=a;
		}
		if(sum>max){
			max=sum;
			maxP=i;
		}
	}
	printf("%d %d",maxP,max);
}