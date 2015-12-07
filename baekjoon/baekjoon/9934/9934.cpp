#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> > tree;

int depth;

void scan(int depth) {
	if (depth != ::depth) scan(depth + 1);

	int t;
	scanf("%d", &t);
	tree[depth - 1].push_back(t);

	if (depth != ::depth) scan(depth + 1);
}

int main() {
	scanf("%d", &depth);

	tree.resize(depth);

	scan(1);

	for (int i = 0; i < depth; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			printf("%d ", tree[i][j]);
		}
		puts("");
	}
}