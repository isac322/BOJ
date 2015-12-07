#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const char out[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main() {
	int n, b;
	scanf("%d%d", &n, &b);

	vector<char> result;
	while (n > 0) {
		result.push_back(out[n % b]);
		n /= b;
	}
	for (int i = result.size() - 1; i >= 0; i--) putchar(result[i]);
}