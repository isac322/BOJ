#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0

int *memAlloc(int size) ;
char memDel(int *ptr) ;

int main() {
	int num, cntNum, sum = 0, maxNum = 0 ;
	int ret ;
	int i ;
	int *input = NULL ;

	scanf("%d %d", &num, &cntNum) ;

	input = memAlloc(num + 1) ;

	for(i = 0; i < num; i++) {
		scanf("%d", &input[i]) ;
		if(i < cntNum)
			sum += input[i] ;
	}
	input[i] = '\0' ;

	maxNum = sum ;

	for(i = 0; i < num - cntNum; i++) {
		sum -= input[i] - input[i + cntNum] ;
		maxNum = sum > maxNum ? sum : maxNum ;
	}

	printf("%d", maxNum) ;

	ret = memDel(input) ;
	if(ret == FALSE)
		return -1 ;

	input = NULL ;
}

int *memAlloc(int size) {
	int *ptr = NULL ;

	if(!ptr) {
		ptr = (int *)malloc(sizeof(int) * size) ;
		return ptr;
	} else
		return NULL ;
}

char memDel(int *ptr) {
	if(!ptr) {
		free(ptr) ;
		return TRUE ;
	} else
		return FALSE ;
}