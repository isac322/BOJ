#include <cstdio>
#include <algorithm>

using namespace std;

int arr[44];
bool check[1001];

int main() {
	for (int i = 0; i < 44; i++) arr[i] = (i + 1)*(i + 2) >> 1;
	for (int i = 0; i < 44; i++) for (int j = i; j < 44; j++) for (int k = j; k < 44; k++) if (arr[i] + arr[j] + arr[k] <= 1000)check[arr[i] + arr[j] + arr[k]] = true;
	int n, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		puts(check[n] ? "1" : "0");
	}
}