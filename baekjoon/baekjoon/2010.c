#include <stdio.h>
main(){
	int sum=1,num=0,max,i;
	scanf("%d",&max);
	for(i=0;i<max;i++){
		scanf("%d",&num);
		sum+=num-1;
	}
	printf("%d",sum);
}