#include <stdio.h>

char mat[5][5], num[26];

char calc() {
	char b = 0, tmp;
	for (int i = 0; i < 5; i++) {
		tmp = 0;
		for (int j = 0; j < 5; j++) tmp += mat[i][j];
		if (!tmp) b++;
	}
	for (int i = 0; i < 5; i++) {
		tmp = 0;
		for (int j = 0; j < 5; j++) tmp += mat[j][i];
		if (!tmp) b++;
	}
	tmp = 0;
	for (int i = 0; i < 5; i++) tmp += mat[i][i];
	if (!tmp) b++;
	tmp = 0;
	for (int i = 0; i < 5; i++) tmp += mat[4 - i][i];
	if (!tmp) b++;
	return b;
}

int main() {
	int i, n;
	for (i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", mat[i] + j);
			num[mat[i][j]] = i * 5 + j;
		}
	}
	for (i = 1; i <= 25; i++) {
		scanf("%d", &n);
		mat[num[n] / 5][num[n] % 5] = 0;
		if (calc() >= 3) {
			printf("%d", i);
			return 0;
		}
	}
}