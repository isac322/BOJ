#include <stdio.h>
#include <string.h>
main(){
	long long result;
	char input[7]={0};
	scanf("%s",input);
	if(!strcmp(input,"black"))
		result=0;
	else if(!strcmp(input,"brown"))
		result=10;
	else if(!strcmp(input,"red"))
		result=20;
	else if(!strcmp(input,"orange"))
		result=30;
	else if(!strcmp(input,"yellow"))
		result=40;
	else if(!strcmp(input,"green"))
		result=50;
	else if(!strcmp(input,"blue"))
		result=60;
	else if(!strcmp(input,"violet"))
		result=70;
	else if(!strcmp(input,"grey"))
		result=80;
	else if(!strcmp(input,"white"))
		result=90;
	scanf("%s",input);
	if(!strcmp(input,"black"))
		result+=0;
	else if(!strcmp(input,"brown"))
		result+=1;
	else if(!strcmp(input,"red"))
		result+=2;
	else if(!strcmp(input,"orange"))
		result+=3;
	else if(!strcmp(input,"yellow"))
		result+=4;
	else if(!strcmp(input,"green"))
		result+=5;
	else if(!strcmp(input,"blue"))
		result+=6;
	else if(!strcmp(input,"violet"))
		result+=7;
	else if(!strcmp(input,"grey"))
		result+=8;
	else if(!strcmp(input,"white"))
		result+=9;
	scanf("%s",input);
	if(!strcmp(input,"black"))
		result*=1;
	else if(!strcmp(input,"brown"))
		result*=10;
	else if(!strcmp(input,"red"))
		result*=100;
	else if(!strcmp(input,"orange"))
		result*=1000;
	else if(!strcmp(input,"yellow"))
		result*=10000;
	else if(!strcmp(input,"green"))
		result*=100000;
	else if(!strcmp(input,"blue"))
		result*=1000000;
	else if(!strcmp(input,"violet"))
		result*=10000000;
	else if(!strcmp(input,"grey"))
		result*=100000000;
	else if(!strcmp(input,"white"))
		result*=1000000000;
	printf("%lld",result);
}