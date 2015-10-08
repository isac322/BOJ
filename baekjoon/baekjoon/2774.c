#include <stdio.h>
#include <string.h>

main() {
	int T, len, cnt;
	int i;
	char a[100] = {0}, b[10] = {0};

	scanf("%d",&T);
	getchar();
	while(T--) {
		gets(a);
		cnt = 0;
		memset(b,0,sizeof(char) * 10);
		len = strlen(a);
		for(i = 0; i < len; i++)
			b[a[i]-'0'] = 1;
		for(i = 0; i < 10; i++)
			if(b[i]) cnt++;
		printf("%d\n",cnt);
	}
}