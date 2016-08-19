#include <stdio.h>
#include <malloc.h>
#include <memory.h>
main(){
	int sum=0,i=0,max=0,*num;
	double a,b;
	scanf("%lf",&a);
	b=a;
	num=(int*)malloc(sizeof(int)*a);
	while(a--){
		scanf("%d",&num[i]);
		if(num[i]>max)
			max=num[i];
		sum+=num[i++];
	}
	printf("%0.2lf",sum/b/max*100);
}