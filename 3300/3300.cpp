#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <algorithm>

using namespace std;
using namespace std::tr1;

struct Node {
	char val;
	vector<Node *> children;

	Node(char val) : val(val) {};
}root('^'), last('&');

typedef vector<Node *> nodeVec;

char pattern[103] = "(", input[101];
int str_index, len;

vector<Node *> insert(Node* parents);
vector<Node *> insert(vector<Node *> parents);

vector<Node *> expand(Node* root) {
	vector<Node *> ret;

	while (pattern[str_index] != ')') {
		const vector<Node *> &tmp = insert(root);

		ret.insert(ret.end(), tmp.begin(), tmp.end());
	}
	str_index++;

	if (str_index == len) return ret;
	return insert(ret);
}

vector<Node *> insert(Node* parents) {
	char &val = pattern[str_index];

	if (val == '(') {
		str_index++;
		return expand(parents);
	}
	else if (val == ')') {
        vector<Node *> ret;
        ret.push_back(parents);
		return ret;
	}
	else if (val == '|') {
		str_index++;
        vector<Node *> ret;
        ret.push_back(parents);
		return ret;
	}
	else {
		Node *root = new Node(pattern[str_index]);

		parents->children.push_back(root);
		str_index++;

		return insert(root);
	}
}

vector<Node *> insert(vector<Node *> parents) {
	char &val = pattern[str_index];

	if (val == '(') {
		str_index++;
		Node *tmp = new Node('0');

		const size_t &l = parents.size();
		for (size_t i = 0; i < l; i++) {
			parents[i]->children.push_back(tmp);
		}

		return expand(tmp);
	}
	else if (val == ')') {
		return parents;
	}
	else if (val == '|') {
		str_index++;
		return parents;
	}
	else {
		Node* root = new Node(pattern[str_index]);

		const size_t &l = parents.size();
		for (size_t i = 0; i < l; i++) {
			parents[i]->children.push_back(root);
		}
		str_index++;

		return insert(root);
	}
}


struct pairHasher {
	size_t operator()(const pair<Node *, int>& t) const {
		void *p = (void *) (t.first);
		int tmp = *((int *) p);

		return (tmp << 7) | t.second;
	}
};

struct nodeComparator {
	bool operator()(Node* const &a, Node* const &b) const {
		const char &v1 = a->val, &v2 = b->val;

		if (v1 == v2) {
			Node *t = a->children[0], *t1 = b->children[0];

			while (true) {
				if (t->val != t1->val) {
					break;
				}

				if (t->children.size() == 0 && t1->children.size() == 0) {
					break;
				}
				t = t->children[0];
				t1 = t1->children[0];
			}

			return t < t1;
		}
		else return v1 < v2;
	}
};

int inputLen;
char missing;
unordered_map< pair<Node *, int>, int, pairHasher> dp;

int solve(Node *root, int level) {
	if (level == inputLen) {
		if (root == &last) return 1;
		else return 0;
	}

	const pair<Node *, int> &p = make_pair(root, level);

	if (dp.find(p) != dp.end()) return dp[p];

	int &ret = dp[p];
	ret = 0;

	const char &ch = root->val;


	if (ch == '0') {
		const vector<Node *> &children = root->children;
		set<Node *, nodeComparator> s(children.begin(), children.end());
		for (set<Node *, nodeComparator>::iterator i = s.begin(); i != s.end(); i++) {
			ret += solve(*i, level);
		}
	}

	else if (ch == '_') {
		const vector<Node *> &children = root->children;
		set<Node *, nodeComparator> s(children.begin(), children.end());
		for (set<Node *, nodeComparator>::iterator i = s.begin(); i != s.end(); i++) {
			ret += solve(*i, level + 1);
		}

		if (ret == 1) missing = input[level];
	}

	else if (ch == input[level]) {
		const vector<Node *> &children = root->children;
		set<Node *, nodeComparator> s(children.begin(), children.end());
		for (set<Node *, nodeComparator>::iterator i = s.begin(); i != s.end(); i++) {
			ret += solve(*i, level + 1);
		}
	}

	return ret;
}


int main() {
	int t;
	scanf("%d\n", &t);

	while (t--) {
		dp.clear();
		gets(pattern + 1);
		gets(input);

		len = strlen(pattern);
		inputLen = strlen(input);

		pattern[len] = ')';
		pattern[++len] = 0;

		root.children.clear();
		str_index = 0;

		const vector<Node *> &tails = insert(&root);
		const size_t &l = tails.size();
		for (size_t i = 0; i < l; i++) {
			tails[i]->children.push_back(&last);
		}

		missing = 0;
		int re = 0;

		set<Node *, nodeComparator> s(root.children.begin(), root.children.end());
		set<Node *, nodeComparator>::iterator i = s.begin();
		for (; i != s.end(); i++) {
			re += solve(*i, 0);
		}

		if (re == 1 && missing != 0) printf("%c\n", missing);
		else if (re == 0) puts("!");
		else puts("_");
	}
}