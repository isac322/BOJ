#include <cstdio>

using namespace std;

#define M 10007

int main() {
	int n;
	scanf("%d", &n);

	int arr[10] = { 1,1,1,1,1,1,1,1,1,1 }, prev[10] = { 1,1,1,1,1,1,1,1,1,1 };

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < 10; j++) arr[0] += arr[j];
		for (int j = 1; j < 10; j++) arr[j] = (M + arr[j - 1] % M - prev[j - 1]) % M;
		for (int j = 0; j < 10; j++) prev[j] = arr[j];
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) sum += arr[i];
	printf("%d", sum%M);
}