#include <stdio.h>
main(){
	int count=0,temp,num,input[3]={0};
	scanf("%d",&num);
	temp=num;
	do{
		if(!(temp/10)){
			input[0]=0;
			input[1]=temp;
		}else{
			input[0]=temp/10;
			input[1]=temp-temp/10*10;
		}
		temp=input[0]-(input[0]+input[1])/10*10+11*input[1];
		count++;
	}while(temp!=num);
	printf("%d",count);
}