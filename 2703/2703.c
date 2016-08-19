#include <stdio.h>
#include <string.h>

main() {
	int test, len ;
	int i ;
	char input[1000] = {0}, key[27] = {0} ;

	scanf("%d", &test) ;
	getchar() ;

	while(test--) {
		gets(input) ;
		gets(key) ;

		len = strlen(input) ;
		for(i = 0; i < len; i++)
			if(input[i] >= 'A' && input[i] <= 'Z')
				input[i] = key[input[i] - 'A'] ;

		puts(input) ;
	}
}