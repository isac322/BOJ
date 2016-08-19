#include <stdio.h>
main(){
    int i,a,b=0;
	for(i=0;i<5;i++){
		scanf("%d",&a);
		b+=a*a;
	}
	printf("%d",b%10);
}