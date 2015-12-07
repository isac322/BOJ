#include <stdio.h>

int main(void) {
	int plus, min, max = 0, people = 0 ;
	int i = 4 ;

	while(i--) {
		scanf("%d %d", &min, &plus) ;
		people += plus - min ;
		if(people > max)
			max = people ;
	}
	printf("%d",max) ;
}