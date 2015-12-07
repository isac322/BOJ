#include <string.h>
main(){char b[128],*p;for(;gets(b);puts(b))while((p=strstr(b,"BUG")))while(p[2])*p=*(p+++3);}