#include <stdio.h>
main(){
	int m,M,t,i=0;
	for(scanf("%d",&m);i<2;i++){
		scanf("%d",&t);
		if(t<m)m=t;
	}
	scanf("%d%d",&M,&t);
	if(t<M)M=t;
	printf("%d",m+M-50);
}