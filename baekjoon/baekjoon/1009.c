a[10][4]={{10,10,10,10},{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}};main(b,c,d){for(gets(&b);~scanf("%d%d",&c,&d);)printf("%d\n",a[c%10][(d+3)%4]);}