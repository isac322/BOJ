#include <memory.h>
#include <string.h>
main(i,c){char a[21],b[11],t[11];scanf("%s %s",a,b);strcpy(t,a);memset(a,48,strlen(b)-strlen(a));strcat(a,t);for(i=c=0;a[i]==b[i]&&i<strlen(b);i++){if(a[i]==56)c++;}printf("%d",c);}