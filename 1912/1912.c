#include <stdio.h>

int main() {
	int n, arr[100001];
	scanf("%d", &n);
	
	scanf("%d", arr);
	int ret = arr[0], t;
	for (int i = 1; i < n; i++) {
		scanf("%d", &t);

		arr[i] = arr[i - 1] + t;

        if (ret < arr[i]) ret = arr[i];
        for (int j = 0; j < i; j++) {
            int tmp = arr[i] - arr[j];
            if (ret < tmp) ret = tmp;
        }
	}

	printf("%d", ret);
}