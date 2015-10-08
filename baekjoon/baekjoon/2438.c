#include <stdio.h>
main(){
    int i,j,a;
    scanf("%d",&a);
    for(i=1;i<=a;i++){
        for(j=0;j<i;j++)
            putchar('*');
        putchar(10);
    }
}