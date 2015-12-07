#include <stdio.h>
main(){
	int max,i;
	char temp[51]={0};
	scanf("%d",&max);
	getchar();
	for(i=0;i<max;i++){
		gets(temp);
		printf("%d. %s\n",i+1,temp);
	}
}