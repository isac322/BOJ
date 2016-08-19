#include <stdio.h>
#include <string.h>
main(){
	char a[11]={0};
	int i,j=0;
	for(i=0;i<5;i++){
		scanf("%s",a);
		if(strstr(a,"FBI")){
			printf("%d ",i+1);
			j++;
		}
	}
	if(!j)
		puts("HE GOT AWAY!");
}