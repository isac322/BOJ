#include <stdio.h>

int main() {
	int caseNum;
	int start[2] = { 0 }, end[2] = { 0 };
	int planetNum;
	int x, y, r;
	int count = 0;

	scanf("%d", &caseNum);
	
	while (caseNum--) {
		count = 0;
		scanf("%d %d %d %d", start, start + 1, end, end + 1);
		scanf("%d", &planetNum);

		while (planetNum--) {
			scanf("%d %d %d", &x, &y, &r);

			if ((((start[0] - x)*(start[0] - x) + (start[1] - y)*(start[1] - y)) < r * r) ^ (((end[0] - x)*(end[0] - x) + (end[1] - y)*(end[1] - y)) < r * r)) count++;
		}
		printf("%d\n", count);
	}
}