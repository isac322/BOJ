#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *key, *stat ;
	int i = 0 ;
	int num = 0 ;

	key  = (char *)calloc(30001, sizeof(char)) ;
	stat = (char *)calloc(30001, sizeof(char)) ;

	gets(stat) ;
	gets(key) ;

	num = strlen(key) ;
	key  = (char *)realloc(key, num + 1) ;
	stat = (char *)realloc(stat,strlen(stat) + 1) ;

	for(; stat[i]; i++) {
		if(stat[i] != 32) {
			stat[i] = (stat[i] - key[i % num] + 96) ;
			if(stat[i] < 'a')
				stat[i] = 'z' - 'a' + stat[i] + 1 ;
		}
	}

	puts(stat) ;
}