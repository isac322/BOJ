#include <stdio.h>
main(){
	unsigned int num,i,count=0;
	scanf("%u",&num);
	for(i=1;num>=i;count++,i++)
		num-=i;
	printf("%u",count);
}