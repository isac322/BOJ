#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int val[300001] = { 0 };
int check[300001] = { 0 };
int cost[300001] = { 0 };
int t;

int cmp(const void *a, const void *b) {
	return *(int *)a > *(int *)b ? 1 : *(int *)a < *(int *)b ? -1 : 0;
}

int sum(int n) {
	int a[4];
	
	if (t == 2) {
		a[0] = cost[4] + cost[1];
		a[1] = cost[4] + cost[1] + cost[2];
		a[2] = cost[4] + cost[1] + cost[3];
		qsort(a, 3, sizeof(int), cmp);
		return a[0];
	} else if ((n + 2) / 3 == t - 1 && (n + 1) / 3 == t - 1) {
		if (n % 3 == 2) {
			a[0] = check[n] ? val[n] : sum(n + 1);
			a[1] = check[n + 1] ? val[n + 1] : sum(n + 2);
			a[2] = check[n + 2] ? val[n + 2] : sum(n + 3);
			qsort(a, 3, sizeof(int), cmp);
			val[n - 1] = cost[n - 1] + a[0];
			check[n - 1] = 1;
			return val[n - 1];
		} else {
			val[n - 1] = cost[n - 1];
			val[n - 1] += check[n + 1] ? val[n + 1] : sum(n + 2);
			check[n - 1] = 1;
			return val[n - 1];
		}
	} else if ((n + 2) / 3 == t) {
		if (n % 3 == 1) {
			val[n - 1] = cost[n - 1] + cost[n];
		} else {
			val[n - 1] = cost[n - 1];
		}
		check[n - 1] = 1;
		return val[n - 1];
	} else if (n % 3 == 1) {
		a[0] = check[n] ? val[n] : sum(n + 1);
		a[1] = check[n + 2] ? val[n + 2] : sum(n + 3);
		a[2] = check[n + 3] ? val[n + 3] : sum(n + 4);
		qsort(a, 3, sizeof(int), cmp);
		check[n - 1] = 1;
		val[n - 1] = cost[n - 1] + a[0];
		return val[n - 1];
	} else if (n % 3 == 2) {
		a[0] = check[n] ? val[n] : sum(n + 1);
		a[1] = check[n + 1] ? val[n + 1] : sum(n + 2);
		a[2] = check[n + 2] ? val[n + 2] : sum(n + 3);
		a[3] = check[n + 3] ? val[n + 3] : sum(n + 4);
		qsort(a, 4, sizeof(int), cmp);
		val[n - 1] = cost[n - 1] + a[0];
		check[n - 1] = 1;
		return val[n - 1];
	} else {
		a[0] = check[n + 1] ? val[n + 1] : sum(n + 2);
		a[1] = check[n + 2] ? val[n + 2] : sum(n + 3);
		check[n - 1] = 1;
		val[n - 1] = cost[n - 1] + (*a > a[1] ? a[1] : *a);
		return val[n - 1];
	}
}

int main() {
	int j = 0;
	while (scanf("%d", &t), t) {
		j++;
		memset(check, 0, sizeof(int) *300001);
		memset(val, 0, sizeof(int) * 300001);
		memset(cost, 0, sizeof(int) *300001);
		for (int i = 0; i < t; i++) {
			scanf("%d %d %d", &cost[i * 3], &cost[i * 3 + 1], &cost[i * 3 + 2]);
		}
		printf("%d. %d\n", j, sum(2));
	}
}