#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n, m, j, k;
	vector<int> s;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) s.push_back(i);

	j = m - 1;
	k = n;

	printf("<");
	for (int i = 0; i < k; i++) {
		printf("%d", s[j]);
		s.erase(s.begin() + j);
		if (n == 1) {
			printf(">");
			break;
		}
		printf(", ");
		j += (m - 1);
		n--;
		j %= n;
	}
}