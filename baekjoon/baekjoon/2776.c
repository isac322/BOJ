#include <stdlib.h>
cmp(const void *a,const void *b){int c=*(int*)a,d=*(int*)b;return c>d?1:c==d?0:-1;}c,a[1000000],d,b,i,t;main(){scanf("%d",&t);while(t--){for(i=0,scanf("%d",&c);i<c;scanf("%d",a+i++));qsort(a,c,sizeof(int),cmp);for(scanf("%d",&d);d--;){scanf("%d",&b);if(bsearch(&b,a,c,sizeof(int),cmp))puts("1");else puts("0");}}}