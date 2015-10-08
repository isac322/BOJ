#include <stdio.h>

int main() {
	int comN, caseN;
	int com[200][2] = {0}, list[100] = {1,0}, Nlist[100] = {0};
	int chk = 1, a, b, cnt = 0;
	int i, k = 0;

	scanf("%d\n%d", &comN, &caseN);

	for(i = 0; i < caseN; i++) {
		scanf("%d %d", &a, &b);
		Nlist[a - 1] = Nlist[b - 1] = 1;
		if (list[a - 1] || list[b - 1]) list[a - 1] = list[b - 1] = 1;
		else if (!list[a - 1] && !list[b - 1]) {
			com[k][0] = a;
			com[k++][1] = b;
		}
	}

	while (chk) {
		chk = 0;
		for (i = 0; i < k; i++) {
			if (com[i][0]) {
				if (list[com[i][0] - 1] || list[com[i][1] - 1]) {
					chk = list[com[i][0] - 1] = list[com[i][1] - 1] = 1;
					com[i][0] = 0;
				}
			}
		}
	}
	for (i = 1; i < 100; i++) if (list[i] && Nlist[i]) cnt++;
	printf("%d", cnt);
}