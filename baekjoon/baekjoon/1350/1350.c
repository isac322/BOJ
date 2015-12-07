main() {
	int a,b[1000],c,i=0;
	long long t=0;
	scanf("%d",&a);
	for(;i<a;i++)scanf("%d",b+i);
	scanf("%d",&c);
	for(i=0;i<a;i++)t+=((b[i]+c-1)/c)*c;
	printf("%lld",t);
}