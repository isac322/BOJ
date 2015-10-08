#include <stdio.h>
main(){
	int a,b,i,c1=0,c2=0;
	scanf("%d%d",&a,&b);
	if(a>b)
		c1++;
	else if(a<b)
		c2++;
	a=b;
	for(i=0;i<6;i++){
		scanf("%d",&b);
		if(a>b)
			c1++;
		else if(a<b)
			c2++;
		a=b;
	}
	if(c1==7)
		puts("descending");
	else if(c2==7)
		puts("ascending");
	else
		puts("mixed");
}