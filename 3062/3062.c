#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
main(){
	int i,j,test,temp,num;
	char *p,Ctemp,check;
	scanf("%d",&test);
	for(i=0;i<test;i++){
		check=1;
		j=0;
		scanf("%d",&temp);
		num=temp;
		while(num/=10)
			j++;
		p=(char*)malloc(sizeof(char)*(j+1));
		sprintf(p,"%d",temp);
		for(j=0;j<strlen(p)/2;j++){
			Ctemp=p[j];
			p[j]=p[strlen(p)-1-j];
			p[strlen(p)-1-j]=Ctemp;
		}
		temp+=atoi(p);
		sprintf(p,"%d",temp);
		for(j=0;j<strlen(p)/2;j++)
			if(p[j]!=p[strlen(p)-1-j])
				check=0;
		printf("%s\n",check ? "YES":"NO");
	}
}