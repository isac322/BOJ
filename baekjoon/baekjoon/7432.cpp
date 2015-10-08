#include <cstdio>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

char str[81];
int starts[40], len;

struct Node {
	map<string, Node> children;
}root;

void insert(Node &root, int index) {
	if (index == len) return;

	string n(str + starts[index]);
	insert(root.children[n], index + 1);
}

void print(Node &root, int depth) {
	map<string, Node>::iterator i = root.children.begin();
	for (; i != root.children.end(); i++) {
		for (int i = 0; i < depth; i++) putchar(' ');
		puts(i->first.c_str());
		print(i->second, depth + 1);
	}
}

int main() {
	int n;
	scanf("%d\n", &n);

	while (n--) {
		len = 1;
		char t;
		int i = 0;
		for (; (t = getchar()) != '\n'; i++) {
			if (t == '\\') {
				starts[len] = i + 1;
				len++;
				str[i] = 0;
			}
			else str[i] = t;
		}
		str[i] = 0;

		insert(root, 0);
	}

	print(root, 0);
}