#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[1000000],n,i;
int main() {
	for(scanf("%d", &n);i<n;i++)scanf("%d",arr+i);
	sort(arr,arr+n);
	for(i=0;i<n;i++) printf("%d\n", arr[i]);
}