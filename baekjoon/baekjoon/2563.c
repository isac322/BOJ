#include <stdio.h>
#include <memory.h>

void main(void) {
	char mat[100][100] = {0} ;
	int x, y, num, xMax = 0, yMax = 0, cnt = 0;
	int i, j ;

	scanf("%d", &num);
	for(i = 0; i < num; i++) {
		scanf("%d %d", &x, &y) ;
		if(x > xMax)
			xMax = x ;
		if(y > yMax)
			yMax = y ;
		for(j = y; j < y + 10; j++)
			memset(&mat[j - 1][x - 1], 1, sizeof(char) * 10) ;
	}

	for(i = 0; i < yMax + 10; i++)
		for(j = 0; j < xMax + 10; j++)
			if(mat[i][j])
				cnt++ ;
	
	printf("%d", cnt) ;
}