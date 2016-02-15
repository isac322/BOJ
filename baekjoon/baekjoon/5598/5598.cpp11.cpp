#include <cstdio>

using namespace std;

int main() {
	char c;
	while ((c = getchar()) != 10) putchar((23 + c - 65) % 26 + 65);
}