#include <stdio.h>
int a=0,b=0;
int f(int n){
	if(n==0){
		a++;
		return 0;
	}else if(n==1){
		b++;
		return 1;
	}else
		return f(n-1)+f(n-2);
}
main(c,d){
	scanf("%d",&c);
	while(c--){
		a=b=0;
		scanf("%d",&d);
		f(d);
		printf("%d %d\n",a,b);
	}
}