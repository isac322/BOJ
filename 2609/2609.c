g(a,b){
    return b?g(b,a%b):a;
}
 
main(a,b,i){
    scanf("%d %d",&a,&b);
    printf("%d\n%d",i,a*b/(i=g(a,b)));
}