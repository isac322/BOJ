#include <stdio.h>

int main() {
	int Tcase = 0, k, n, tmp = 0;
	int M[15][14] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,0};
	int i = 0, j = 0, h = 0;

	for(i = 1; i < 15; i++) {
		for(j = 0; j < 14; j++, tmp = 0) {
			for(h = 0; h <= j; h++)
				tmp += M[i-1][h] ;
			M[i][j] = tmp;
		}
	}
	scanf("%d",&Tcase);
	while(Tcase--) {
		scanf("%d %d", &k, &n);
		printf("%d\n", M[k][n-1]);
	}
}