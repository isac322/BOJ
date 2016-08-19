#include <stdio.h>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	list<int> l;
	for (int i = 0; i < n; i++) l.push_back(i + 1);
	list<int>::iterator iter = l.begin();
	while (!l.empty()) {
		for (int i = 0; i < m - 1; i++) {
			iter++;
			if (iter == l.end()) iter = l.begin();
		}
		if (l.size() == n) printf("<%d", *iter);
		else printf(", %d", *iter);
		iter = l.erase(iter);
		if (iter == l.end()) iter = l.begin();
	}
	printf(">\n");
}