#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct PERSON {
	unsigned char age;
	int time;
	char name[101];

	bool operator< (const PERSON &p) const {
		if (p.age == age) return p.time > time;
		else return p.age > age;
	}
}person;

int main() {
	int t;
	scanf("%d", &t);
	person people[100000];

	for (int i = 0; i < t; i++) {
		scanf("%d %s", &people[i].age, people[i].name);
		people[i].time = i;
	}

	sort(people, people + t);

	for (int i = 0; i<t; i++) printf("%d %s\n", people[i].age, people[i].name);
}