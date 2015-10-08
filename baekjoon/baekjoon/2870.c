#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const char *s1, const char *s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if (len1 == len2)
		return strcmp(s1, s2) < 0;
	else
		return len1 < len2;
}

int main() {
	int max, len;
	char re[500][101] = { 0 };
	int i, j,k = 0, l = 0 ;
	char mat[100][101] = { 0 };
	char *p;

	scanf("%d", &max);
	getchar();
	for (i = 0; i < max; i++) {
		gets(mat[i]);
		len = strlen(mat[i]);
		for (j = 0; j < len; j++) {
			if (!isdigit(mat[i][j])) mat[i][j] = 0;
		}
		p = mat[i];
		while (p - mat[i] < len - 1) {
			j = 0;
			while (!(*p) || (*p == '0' && isdigit(*(p+1)))) p++;
			if (p - mat[i] > len - 1) break;
			while (*p) {
				re[k][j++] = *p;
				p++;
			}
			k++;
		}
	}
	char tmp[101] = { 0 };

	for (i = 0; i < k - 1; ++i) {
		int done = 1;
		for (j = 0; j < k - 1; ++j) {
			if (!cmp(re[j], re[j + 1])) {
				strcpy(tmp, re[j]);
				strcpy(re[j], re[j + 1]);
				strcpy(re[j + 1], tmp);
				done = 0;
			}
		}

		if (done) break;
	}
	for (i = 0; i < k; i++)
		puts(re[i]);
}