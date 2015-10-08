#include <stdio.h>
#include <stdlib.h>

void memDel(void *ptr) ;
void *memAlloc(int size, int castSize) ;

int main() {
	short *order = NULL ;
	int i ;
	int orderNum, diceNum, dice, loc = 0 ;

	scanf("%d %d", &orderNum, &diceNum) ;

	order = (short *)memAlloc(orderNum, sizeof(short)) ;

	for(i = 0; i < orderNum; i++)
		scanf("%d", order + i) ;
	for(i = 0; i <= diceNum; i++) {
		if(loc >= (orderNum - 1)) {
			printf("%d", i) ;

			memDel(order) ;
			order = NULL ;
			return 0;
		}
		scanf("%d", &dice) ;
		loc += dice ;
		if(loc >= (orderNum - 1)) {
			printf("%d", i + 1) ;

			memDel(order) ;
			order = NULL ;
			return 0;
		}
		loc += order[loc] ;
	}
}

void *memAlloc(int size, int castSize) {
	void *ptr = NULL ;

	if(!ptr) {
		ptr = calloc(size, castSize) ;
		return ptr ;
	}
	else
		return ;
}

void memDel(void *ptr) {
	if(!ptr) {
		free(ptr) ;
		return ;
	} else
		return ;
}