/*2743
#include <stdio.h>
#include <string.h>

int main(void) {
	char A[100] = {0} ;
	gets(A);
	printf("%d",strlen(A)) ;
}
*/
#include <stdio.h>

int main(void) {
	char input[101] = {0} ;
	int i ;
	gets(input) ;
	for(i = 0; input[i]; i++) {
		if(input[i] >= 'A' && input[i] <= 'Z')
			input[i] += 32 ;
		else
			input[i] -= 32 ;
	}
	puts(input) ;
}