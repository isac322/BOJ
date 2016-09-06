#include <stdio.h>
#include <stdlib.h>

int main() {
	int *plates = NULL, *table = NULL;
	int platesNum, varietyNum, k, cupon, choice = 0, cnt, tmp;
	int i = 0;

	scanf("%d %d %d %d", &platesNum, &varietyNum, &k, &cupon);
	plates = (int *)calloc(platesNum, sizeof(int));
	table = (int *)calloc(varietyNum + 1, sizeof(int));
	cnt = k;
	for (; i < platesNum; i++) {
		scanf("%d", plates + i);
		if (i < k) {
			if (table[plates[i]]) cnt--;
			table[plates[i]]++;
		}
	}

	choice = cnt + (table[cupon] ? 0 : 1);
	for (i = 0; i < platesNum; i++) {
		if (!(--table[plates[i%platesNum]])) cnt--;
		if ((++table[plates[(i + k)%platesNum]]) == 1) cnt++;
		tmp = table[cupon] ? 0 : 1;
		if (choice < cnt + tmp) choice = cnt + tmp;
	}
	printf("%d", choice);
}