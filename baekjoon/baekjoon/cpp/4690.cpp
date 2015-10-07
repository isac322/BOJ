#include <cstdio>

using namespace std;

int main() {
	for (int i = 2; i <= 100; i++) {
		int des = i*i*i;

		for (int j = 2; j < i; j++) {
			int num = j*j*j;
			for (int k = j; k < i; k++) {
				num += k*k*k;
				for (int l = k; l < i; l++) {
					if (des == num + l*l*l) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
					}
				}
				num -= k*k*k;
			}
		}
	}
}