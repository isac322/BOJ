#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

vector<string> patterns;
string target;

struct Node {
	vector<Node *> next = vector<Node *>(26, nullptr);
	char ch;
	bool last = false;
	Node *failure, *output = nullptr;

	explicit Node(char ch = '\0') : ch(ch), failure(&root) {}

	static Node root;
};
Node Node::root;

void build() {
	for (const auto &str : patterns) {
		Node *p = &Node::root;
		auto iter = str.begin();

		while (iter != str.end() && p->next[*iter - 'a'] != nullptr) {
			p = p->next[*iter - 'a'];
			iter++;
		}

		for (; iter != str.end(); iter++) {
			auto *node = new Node(*iter);
			p->next[*iter - 'a'] = node;
			p = node;
		}

		p->last = true;
	}

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

					if (pf->next[q->ch - 'a'] != nullptr) {
						q->failure = pf->next[q->ch - 'a'];

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

bool search() {
	auto *p = &Node::root;

	for (const char &c : target) {
		while (p != &Node::root && p->next[c - 'a'] == nullptr)	p = p->failure;

		if (p->next[c - 'a'] != nullptr) {
			p = p->next[c - 'a'];

			if (p->last || p->output != nullptr) return true;
		}
	}

	return false;
}

char str[10001];

int main() {
	int n, m;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		gets(str);
		patterns.emplace_back(str);
	}

	build();

	scanf("%d\n", &m);
	for (int i = 0; i < m; i++) {
		gets(str);
		target = str;
		puts(search() ? "YES" : "NO");
	}
}