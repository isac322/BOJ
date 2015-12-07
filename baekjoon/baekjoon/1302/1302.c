#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return strcmp((char*)a,(char*)b);
}
main(){
	char data[1000][51]={0};
	int i,j=0,count,max,hi=0,temp;
	scanf("%d",&max);
	for(i=0;i<max;i++)
		scanf("%s",data[i]);
	qsort(data,max,sizeof(char)*51,cmp);
	for(i=0;i<max;i++){
		count=0;
		for(j=i+1;j<max;j++)
			if(!strcmp(data[i],data[j]))
				count++;
		if(hi<count){
			hi=count;
			temp=i;
		}
	}
	puts(data[temp]);
}