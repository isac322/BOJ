#include <stdio.h>
#define E -1
#define W 1
#define N -2
#define S 2

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	printf("%d\n", t);
	while (t--) {
		char mat[201][201] = { 0 };
		int top = 100, buttom = 100, right = 0;
		int x = 0, y = 100;
		char dir = E;
		char move;
		mat[y][x] = '.';
		while ((move = getchar()) > 'A') {
			switch (move) {
				case 'F':
					switch (dir) {
						case W: x--; break;
						case E: x++; break;
						case N: y--; break;
						case S: y++; break;
					}
					break;
				case 'B':
					switch (dir) {
						case W: x++; break;
						case E: x--; break;
						case N: y++; break;
						case S: y--; break;
					}
					dir *= -1;
					break;
				case 'R':
					switch (dir) {
						case W: y--; dir = N; break;
						case E: y++; dir = S; break;
						case N: x++; dir = E; break;
						case S: x--; dir = W; break;
					}
					break;
				case 'L':
					switch (dir) {
						case W: y++; dir = S; break;
						case E: y--; dir = N; break;
						case N: x--; dir = W; break;
						case S: x++; dir = E; break;
					}
					break;
			}
			mat[y][x] = '.';
			if (x > right) right = x;
			if (y < top) top = y;
			if (y > buttom) buttom = y;
		}
		right++;
		buttom++;
		top--;
		printf("%d %d\n", buttom - top + 1, right + 1);
		for (int i = top; i <= buttom; i++) {
			for (int j = 0; j <= right; j++) {
				putchar(mat[i][j] ? '.' : '#');
			}
			puts("");
		}
	}
}