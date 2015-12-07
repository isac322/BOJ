#include <stdio.h>

int main() {
	unsigned int num1, num2;
	unsigned int ucnum;

	scanf("%d%d",&num1,&num2);

	ucnum = num1>num2 ? num1 : num2;

	for(; ucnum>0;--ucnum) {
		if(num1%ucnum==0 && num2%ucnum==0) {
			printf("%d\n%d",ucnum,num1*num2/ucnum);
			break;
		}
	}
}