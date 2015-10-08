#include <stdio.h>
#include <string.h>

int main() {
	int t;
	char c[3];
	double a;

	for(scanf("%d", &t);t--;) {
		scanf("%lf %s", &a, c);
		if (!strcmp(c, "kg")) printf("%0.4lf lb\n",a*2.2046);
		else if (!strcmp(c, "lb")) printf("%0.4lf kg\n",a*0.4536);
		else if (*c=='l') printf("%0.4lf g\n",a*0.2642);
		else printf("%0.4lf l\n",a*3.7854);
	}
}