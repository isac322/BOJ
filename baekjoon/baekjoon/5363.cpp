#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++) {
		queue<string> que;
		string str;
		char s;
		while (1) {
			cin >> str;
			s = cin.get();
			que.push(str);
			if (s == 10) break;
		}
		que.push(que.front());
		que.pop();
		que.push(que.front());
		que.pop();
		while (!que.empty()) {
			cout << que.front() << " ";
			que.pop();
		}
		cout << endl;
	}
}