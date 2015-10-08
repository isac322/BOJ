#include <math.h>
main(){double a,b;while(1){scanf("%lf%lf",&a,&b);if(!a&&!b)break;printf("%0.3lf\n",sqrt(1-pow(b/a,2)));}}