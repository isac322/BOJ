#include <stdio.h>
int a,i,max=1;
int h(int a){
	if(a==1)
		return;
	if(a%2){
		a=a*3+1;
		if(max<a)
			max=a;
	}else{
		a/=2;
		if(max<a)
			max=a;
	}
	if(a==1)
		return;
	else
		h(a);
}
main(){
	scanf("%d",&i);
	while(i--){
		scanf("%d",&a);
		max=a;
		h(a);
		printf("%d\n",max);
	}
}