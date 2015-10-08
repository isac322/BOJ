#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>
main(){
	int max,i,j,check,lenth;
	char **str,comstr[51]={0};
	scanf("%d",&max);
	check=getchar();
	str=(char**)malloc(sizeof(char*)*max);
	for(i=0;i<max;i++)
		str[i]=(char*)malloc(sizeof(char)*51);
	for(i=0;i<max;i++){
		gets(str[i]);
	}
	lenth=strlen(*str);
	for(i=1;i<max;i++)
		if(lenth<strlen(*(str+i))) lenth=strlen(*(str+i));
	for(i=0;i<lenth;i++){
		check=1;
		for(j=0;j<max-1;j++){
			if(*(*(str+j)+i)==*(*(str+(j+1))+i)&&check==1) check=1;
			else{
				check=0;
				break;
			}
		}
		if(check==1)
			comstr[i]=*(*(str+j)+i);
		else
			comstr[i]='?';
	}
	puts(comstr);
}