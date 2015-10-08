#include <stdio.h>
main(){
	int sum=0,a[10],i;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++){
		sum+=a[i];
		if(sum==100)
			break;
		else if(200==sum*2+a[i+1]){
			sum+=a[i+1];
			break;
		}else if(200<sum*2+a[i+1])
			break;
	}
	printf("%d",sum);
}