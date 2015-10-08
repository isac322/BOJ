#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, cnt = 0, tmp = 0;
	int i = 0, j = 0;
	short *p;

	scanf("%d %d", &n, &m);
	
	p = (short*)calloc(n,sizeof(short));
	
	for(; i < n; i++)
		scanf("%d", p + i);

	for(i = 0; i < n; i++, tmp = 0) {
		for(j = i; tmp < m && j < n; j++)
			tmp += p[j];
		if(tmp == m) cnt++;
	}

	printf("%d",cnt);
}