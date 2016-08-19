#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

string target;

struct Node {
	Node *next[4] = {nullptr};
	char ch;
	bool last = false;
	Node *failure, *output = nullptr;

	explicit Node(char ch = '\0') : ch(ch), failure(&root) { }

	static Node root;
};

Node Node::root;

inline int getIndex(char ch) {
	switch (ch) {
		case 'A':
			return 0;
		case 'C':
			return 1;
		case 'G':
			return 2;
		default:
			return 3;
	}
}

void add(const string &str) {
	Node *p = &Node::root;
	auto iter = str.begin();

	while (iter != str.end() && p->next[getIndex(*iter)] != nullptr) {
		p = p->next[getIndex(*iter)];
		iter++;
	}

	for (; iter != str.end(); iter++) {
		auto *node = new Node(*iter);
		p->next[getIndex(*iter)] = node;
		p = node;
	}

	p->last = true;
}

void build() {
	queue<Node *> que;
	que.emplace(&Node::root);

	while (!que.empty()) {
		auto *p = que.front();
		que.pop();

		for (auto q : p->next) {
			if (q != nullptr) {
				que.emplace(q);

				auto pf = p;
				while (pf != pf->failure) {
					pf = pf->failure;

					if (pf->next[getIndex(q->ch)] != nullptr) {
						q->failure = pf->next[getIndex(q->ch)];

						if (q->failure->last) {
							q->output = q->failure;
						}
						else {
							q->output = q->failure->output;
						}

						break;
					}
				}
			}
		}
	}
}

size_t length;

size_t search() {
	size_t matched = 0;

	auto *p = &Node::root;

	for (auto i = 1; i <= length; i++) {
		const auto &c = target[i - 1];

		while (p != &Node::root && p->next[getIndex(c)] == nullptr) p = p->failure;

		if (p->next[getIndex(c)] != nullptr) {
			p = p->next[getIndex(c)];

			if (p->last) matched++;
			auto *tmp = p->output;
			while (tmp != nullptr && (tmp->last || tmp->output != nullptr)) {
				matched++;
				tmp = tmp->output;
			}
		}
	}

	return matched;
}

string pattern;

int main() {
	size_t t, n;
	scanf("%zd\n", &t);

	while (t--) {
		Node::root.next[0] = Node::root.next[1] = Node::root.next[2] = Node::root.next[3] = nullptr;
		target.clear();
		pattern.clear();

		scanf("%zd %zd\n", &length, &n);
		for (size_t i = 0; i < length; i++) target.push_back(getchar());
		getchar();
		for (size_t i = 0; i < n; i++) pattern.push_back(getchar());
		getchar();

		add(pattern);
		for (auto i = pattern.begin(); i != pattern.end() - 1; i++) {
			for (auto j = pattern.end(); i + 1 != j; j--) {
				reverse(i, j);
				add(pattern);
				reverse(i, j);
			}
		}

		build();

		printf("%zd\n", search());
	}
}