#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	char str[5][16] = { 0 };

	gets(str[0]);
	gets(str[1]);
	gets(str[2]);
	gets(str[3]);
	gets(str[4]);

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j][i]) putchar(str[j][i]);
		}
	}
}