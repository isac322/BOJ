#include <math.h>
main(){int in,i=1,cnt=0;scanf("%d", &in);for(;in>=(int)pow(10,i);i++)cnt+=i*9*(int)pow(10,i-1);printf("%d",(in-(int)pow(10,i-1)+ 1)*i+cnt);}