#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}
 
int main() {
    int a, b;
    int i, j = 0;
    char c[500000][21], d[500000][21], tmp[21]; 
     
    scanf("%d %d\n", &a, &b);
    for (i = 0; i < a; i++) gets(c[i]);
    qsort(c, a, sizeof(char)* 21, cmp);
    for (i = 0; i < b; i++) {
        gets(tmp);
        if (bsearch(tmp, c, a, sizeof(char)* 21, cmp)) strcpy(d[j++], tmp);
    }
    qsort(d, j, sizeof(char)* 21, cmp);
    printf("%d\n", j);
    for (i = 0; i < j; i++) puts(d[i]);
}
