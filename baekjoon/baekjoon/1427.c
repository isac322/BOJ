#include <stdio.h>
#include <malloc.h>
#include <memory.h>
main(){
	int num,temp,i=1,j,k;
	char *p;
	scanf("%d",&num);
	temp=num;
	while(temp/=10)
		i++;
	p=(char*)malloc(sizeof(char)*(i+1));
	sprintf(p,"%d",num);
	for(j=0;j<i-1;j++){
		for(k=0;k<i-j;k++){
			if(p[k]<p[k+1]){
				temp=p[k];
				p[k]=p[k+1];
				p[k+1]=temp;
			}
		}
	}
	puts(p);
}