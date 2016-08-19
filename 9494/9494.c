#include <stdio.h>
#include <string.h>

int main() {
	int line = 0, loc;
	char state[101] = "";
	int i = 0;

	while (1) {
		scanf("%d", &line);
		getchar();
		if (!line) break;

		for (loc = 0, i = 0; i < line; i++) {
			gets(state);
			while (strlen(state) > loc && state[loc] != ' ') loc++;
		}
		printf("%d\n", loc + 1);
	}
}