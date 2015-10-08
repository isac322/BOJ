#include <stdio.h>
main(){
	char b;
	for(scanf("%c",&b),putchar(b);~scanf("%c",&b);){
		if(b==45){
			scanf("%c",&b);
			putchar(b);
		}
	}
}