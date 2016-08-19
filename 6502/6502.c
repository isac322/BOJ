#include <stdio.h>

int main(){
	int cnt = 1;
	int r, w, l;
	while (1) {
		scanf("%d", &r);
		if (!r) break;
		scanf("%d %d", &w, &l);
		printf("Pizza %d %s on the table.\n", cnt++, w * w + l * l <= 4 * r * r ? "fits" : "does not fit");
	}
}