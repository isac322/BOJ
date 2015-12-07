#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct student {
	char name[11];
	char a, b, c;

	bool operator<(const student &right) const {
		if (a == right.a) {
			if (b == right.b) {
				if (c == right.c) {
					return strcmp(name, right.name) < 0;
				} else return c > right.c;
			} else return b < right.b;
		} else return a > right.a;
	}
};

int main() {
	int n;
	student students[100000];

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%s %hhd %hhd %hhd", students[i].name, &students[i].a, &students[i].b, &students[i].c);

	sort(students, students + n);
	for (int i = 0; i < n; ++i) puts(students[i].name);
}