#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b ;
}

int main() {
	int i = 0 ;
	int total = 0, over1 = 0, check = 1, tmp = 0 ;
	int mat[9] = {0}, cpy[9] = {0} ;
	int *p1 = NULL, *p2 = NULL ;

	for(;i < 9; i++) {
		scanf("%d", mat+i) ;
		total += mat[i] ;
		cpy[i] = mat[i] ;
	}

	qsort(mat, 9, sizeof(int), cmp) ;

	for(over1 = total - 100, i = 1; i <= over1 / 2 && check; i++) {
		tmp = over1 - i ;
		p1 = (int*)bsearch(&i, mat, 9, sizeof(int), cmp);
		p2 = (int*)bsearch(&tmp, mat, 9, sizeof(int), cmp);
		if(p1 && p2)
			check = 0 ;
	}

	for(i = 0; i < 9; i++)
		if(cpy[i] != *p1 && cpy[i] != *p2)
			printf("%d\n", cpy[i]) ;
}