#include <queue>
#include <cstdio>
#include <cctype>

using namespace std;

class FastIO {
	int fd, bufsz;
	char *buf, *cur, *end;
public:
	FastIO(int _fd = 0, int _bufsz = 1 << 20) : fd(_fd), bufsz(_bufsz) {
		buf = cur = end = new char[bufsz];
	}
	~FastIO() {
		delete[] buf;
	}
	bool readbuf() {
		cur = buf;
		end = buf + bufsz;
		while (true) {
			size_t res = fread(cur, sizeof(char), end - cur, stdin);
			if (res == 0) break;
			cur += res;
		}
		end = cur;
		cur = buf;
		return buf != end;
	}
	int readint() {
		while (true) {
			if (cur == end) readbuf();
			if (isdigit(*cur) || *cur == '-') break;
			++cur;
		}
		bool sign = true;
		if (*cur == '-') {
			sign = false;
			++cur;
		}
		int ret = 0;
		while (true) {
			if (cur == end && !readbuf()) break;
			if (!isdigit(*cur)) break;
			ret = ret * 10 + (*cur - '0');
			++cur;
		}
		return sign ? ret : -ret;
	}
};

int main() {
	FastIO io;
	typedef pair<int, int> PII;
	deque<PII> que;
	int  n = io.readint(), l = io.readint(), a;
	for (int i = 0; i < n; i++) {
		a = io.readint();

		while (que.size() && que.front().second <= i - l) que.pop_front();
		while (que.size() && que.back().first >= a) que.pop_back();
		que.emplace_back(a, i);

		printf("%d ", que.front().first);
	}
}