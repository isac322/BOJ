#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int cmp(const void *a, const void *b) {
    char *c = (char *)a, *d = (char *)b;
    int len1 = strlen(c), len2 = strlen(d);
 
    if (len1 == len2) return strcmp(c, d);
    else return len1 - len2;
}
 
int main() {
    int num;
    int i;
    char mat[20000][51] = { "" };
 
    scanf("%d\n", &num);
    for (i = 0; i < num; i++) gets(mat[i]);
    qsort(mat, num, sizeof(char)* 51, cmp);
    for (i = 0; i < num; i++) if (strcmp(mat[i], mat[i + 1])) puts(mat[i]);
}