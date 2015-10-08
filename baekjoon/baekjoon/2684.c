#define A m+=getchar()-84?1:0;m<<=1
main(t){for(scanf("%d\n",&t);t--;getchar()){int c[8]={0},m=0,i=0;A;A;for(;i<38;i++,m&=7){A;c[m>>1]++;}for(i=0;i<8;printf("%d ",c[i++]));puts("");}}