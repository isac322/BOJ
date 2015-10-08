#include <stdio.h>
#define BASE 10000
#define DIGS 4
typedef unsigned short word;
word A[1000] = {1,};
int N = 1;
int main()
{
	int c;
	int i,j;
	int n;
	int count=0;
	scanf("%d",&n);
	for(i=2; i <= n; i++) {
		c = 0;
		for(j=0; j < N; j++) {
			c += A[j] * i;
			A[j] = c % BASE;
			c /= BASE;
		}
		if(c) {
			A[j] = c % BASE;
			c /= BASE;
			N++;
		}
	}
	for(i=0; !A[i]; i++)
		count+=4;
	for(j=10; j<=BASE; j*=10) {
		if(A[i]%j == 0)
			count++;
		else
			break;
	}
	printf("%d",count);
}