#define S(a,b,c) a-b?b-c?b:a:c
a[6],i=6;main(){while(i--)scanf("%d",a+i);printf("%d %d",S(a[1],a[3],a[5]),S(*a,a[2],a[4]));}