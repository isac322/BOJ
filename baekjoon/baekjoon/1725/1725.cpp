#include <cstdio>

using namespace std;

int arr[100000] = { 0 };

int solve(int left, int right) {
	if (left == right) return arr[left];

	int mid = (left + right) >> 1;
	const int &a = solve(left, mid), &b = solve(mid + 1, right);

	int &p_left = mid, p_right = mid + 1;
	int max = a > b ? a : b, vol, height;

	int &left_wall = arr[p_left], &right_wall = arr[p_right];

	if (left_wall > right_wall) {
		vol = right_wall << 1;
		height = right_wall;
	}
	else {
		vol = left_wall << 1;
		height = left_wall;
	}

	if (max < vol) max = vol;
	while (p_left != left || p_right != right) {
		int &left_wall = arr[p_left], &right_wall = arr[p_right];

		if (p_left == left) p_right++;
		else if (p_right == right) p_left--;
		else if (arr[p_left - 1] > arr[p_right + 1]) p_left--;
		else p_right++;

		int t = arr[p_left] > arr[p_right] ? arr[p_right] : arr[p_left];

		vol = (t > height ? height : t) * (p_right - p_left + 1);
		height = t > height ? height : t;
		if (max < vol) max = vol;
	}

	return max;
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);

	printf("%d\n", solve(0, n - 1));
}