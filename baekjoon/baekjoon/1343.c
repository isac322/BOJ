#include <stdio.h>
#include <string.h>

main() {
	int i,count = 0;
	char a[500],b[500]={0};

	gets(a);
	for(i=0;i<strlen(a);i++) {
		if(a[i] == 'X')
			count++;
		else if(a[i] == '.' && count % 2) {
			puts("-1");
			return;
		} else if(a[i] == '.' && count == 2) {
			strcat(b,"BB.");
			count = 0;
		} else if(a[i] == '.')
			strcat(b,".");
		if(count == 4) {
			strcat(b,"AAAA");
			count = 0;
		}
	}
	if(count % 2) {
		puts("-1");
		return;
	} else if(count == 2)
		strcat(b,"BB");
	puts(b);
}