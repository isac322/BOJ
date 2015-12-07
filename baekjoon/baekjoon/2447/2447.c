#include <stdio.h>
#include <memory.h>

int main() {
    char mat[2188][2188] = { "*" };
	int length;
	scanf("%d", &length);
	for (int i = 1; i < length / 3; i *= 3) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i; k++) {
				memcpy(mat[j + k] + i, mat[j], sizeof(char) * i);
				memcpy(mat[j + k] + (i << 1), mat[j], sizeof(char) * i);
				memcpy(mat[(i << 1) + k], mat[k], sizeof(char) * i);
				memcpy(mat[(i << 1) + k] + i, mat[k], sizeof(char) * i);
				memcpy(mat[(i << 1) + k] + (i << 1), mat[k], sizeof(char) * i);
			}
		}
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i; k++) {
				memcpy(mat[i + k], mat[k], sizeof(char) * i);
				memset(mat[i + k] + i, ' ', sizeof(char) * i);
				memcpy(mat[i + k] + (i << 1), mat[k], sizeof(char) * i);
			}
		}
	}
	for (int i = 0; i < length / 3; i++) printf("%s%s%s\n", mat[i], mat[i], mat[i]);
	char tmp[2188] = "";
	memset(tmp, ' ', sizeof(char) * length / 3);
	for (int i = 0; i < length / 3; i++) printf("%s%s%s\n", mat[i], tmp, mat[i]);
	for (int i = 0; i < length / 3; i++) printf("%s%s%s\n", mat[i], mat[i], mat[i]);
	if (length == 1) puts("*");
}