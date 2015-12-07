#include <cstdio>
#include <cstring>

using namespace std;

int arr[10000], len = 0;

struct Node {
	int val;
	Node *left, *right;

	Node(int val) : val(val), left(NULL), right(NULL) {};
}*root;

Node* insert(Node *root, int val) {
	if (root == NULL) root = new Node(val);
	else {
		if (root->val < val) root->right = insert(root->right, val);
		else root->left = insert(root->left, val);
	}

	return root;
}

void make(int start, int end) {
	root = insert(root, arr[start]);

	for (int i = start + 1; i <= end; i++) {
		if (arr[start] < arr[i]) {
			root->right = insert(root->right, arr[i]);
		}
		else {
			root->left = insert(root->left, arr[i]);
		}
	}
}

void post(Node *root) {
	if (root == NULL) return;
	post(root->left);
	post(root->right);
	printf("%d\n", root->val);
}

int main() {
	for (; ~scanf("%d", arr + len); len++);
	make(0, len - 1);
	post(root);
}