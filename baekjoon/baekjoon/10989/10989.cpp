#include <cstdio>
#include <algorithm>
#define gc getchar_unlocked

inline void fastRead_int(int &x) {
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) x = (x << 1) + (x << 3) + c - 48;
}

int main() {
	int arr[10001] = { 0 }, n, t;
	register int i = 0, j;
	fastRead_int(n);
	for (; i < n; i++) {
		fastRead_int(t);
		arr[t]++;
	}
	register char str[8];
	for (i = 1; i < 10001; i++) {
		sprintf(str, "%d", i);
		for (j = 0; j < arr[i]; j++) puts(str);
	}
}