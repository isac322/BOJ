#include <stdio.h>
#include <string.h>

int main() {
	int t;
	int num;
	int i;
	char a[12];
	
	scanf("%d", &t);
	while (t--) {
		a[0] = '0';
		scanf("%d", &num);
		sprintf(a + 1, "%d", num);
		for (i = strlen(a) - 1; i > 1;i--) {
			if (a[i] > '4') a[i - 1]++;
			a[i] = '0';
		}
		if (a[1] > '9') {
			a[1] = '0';
			a[0] = '1';
		}
		printf("%d\n", atoi(a));
	}
}