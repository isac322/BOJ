#include <stdio.h>

int main() {
	double d, s, s1;

	for (scanf("%lf %lf %lf", &d, &s, &s1); d && s && s1; scanf("%lf %lf %lf", &d, &s, &s1)) {
		int sec = (int)((d/s - d/s1)*3600 + 0.5);
		printf("%0d:%02d:%02d\n", sec/3600, sec%3600/60, sec%60);
	}
}