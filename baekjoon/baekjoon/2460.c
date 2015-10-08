#include <stdio.h>
main(){
	int a,b,i,j=0,max=0;
	for(i=0;i<10;i++){
		scanf("%d %d",&a,&b);
		j+=b-a;
		if(j>max)
			max=j;
	}
	printf("%d",max);
}