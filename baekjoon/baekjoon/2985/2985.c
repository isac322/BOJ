#include <stdio.h>

int main() {
	int a,b,c,i;
	scanf("%d %d %d", &a, &b, &c);
	if(a + b == c) printf("%d+%d=%d",a,b,c);
	else if(a - b == c) printf("%d-%d=%d",a,b,c);
	else if(a * b == c) printf("%d*%d=%d",a,b,c);
	else if((double)a / b == c) printf("%d/%d=%d",a,b,c);
	else if(a == b + c) printf("%d=%d+%d",a,b,c);
	else if(a == b - c) printf("%d=%d-%d",a,b,c);
	else if(a == b * c) printf("%d=%d&%d",a,b,c);
	else if(a == (double)b / c) printf("%d=%d/%d",a,b,c);
}