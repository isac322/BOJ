#include <stdio.h>
int get_gcd(int a,int b){
	int x;
	while(b){
		x=a%b;
		a=b;
		b=x;
	}
	return a;
}
main(){
	int n,a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",(a*b)/get_gcd(a,b));
	}
}