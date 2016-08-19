#include <stdio.h>
#include <string.h>

int main() {
	int n,len,maktmp;
	int i,j;
	char tmp[10] = {0};

	scanf("%d", &n);
	for(i = n / 2; i < n; i++) {
		sprintf(tmp,"%d",i);
		len = strlen(tmp);
		maktmp = i;
		for(j=0;j<len;j++)
			maktmp += tmp[j] - '0';
		if(maktmp == n) break;
	}
	printf("%d", i == n ? 0 : i);
}