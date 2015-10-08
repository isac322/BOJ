#include <stdio.h>
main(){
	long long a,b;
	scanf("%lld %lld",&a,&b);
	printf("%lld",a>b ? a-b:b-a);
}