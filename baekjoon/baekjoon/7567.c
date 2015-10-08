#include <stdio.h>
main(){
	char a,b;
	int len=10;
	a=getchar();
	while(1){
		b=getchar();
		if(b<40) break;
		len+=5;
		if(a!=b)
			len+=5;
		a=b;
	}
	printf("%d",len);
}