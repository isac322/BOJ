main(){int i,b=1,n,c=1,d=1,a[100000]={0};scanf("%d",&n);for(i=0;i<n;i++)scanf("%d",&a[i]);for(i=1;i<n;i++){if(d>b)b=d;if(c>b)b=c;if(a[i]<=a[i-1])d++;else d=1;if(a[i]>=a[i-1])c++;else c=1;}if(d>b)b=d;if(c>b)b=c;printf("%d\n",b);}