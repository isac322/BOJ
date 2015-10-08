#include <stdio.h>
main(){
	int a,b[3],i;
	char c[3][50]={"advertise","does not matter","do not advertise"};
	scanf("%d",&a);
	while(a--){
		for(i=0;i<3;i++)
			scanf("%d",&b[i]);
		if(b[0]+b[2]<b[1])
			i=0;
		else if(b[0]+b[2]==b[1])
			i=1;
		else
			i=2;
		puts(c[i]);
	}
}