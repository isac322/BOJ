#include <stdio.h>
#include <memory.h>
main(){
	int a,b,c,i,j,e,d[500]={0};
	scanf("%d",&a);
	for(i=0;i<a;i++){
		e=0;
		memset(d,0,sizeof(d));
		scanf("%d%d",&b,&c);
		for(j=0;j<b;j++){
			scanf("%d",&c);
			if(d[c-1])
				e++;
			else d[c-1]=1;
		}
		printf("%d\n",e);
	}
}