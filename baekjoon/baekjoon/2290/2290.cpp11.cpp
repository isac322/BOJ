#include <cstdio>
#define q for (int t = s; t--; putchar(' '));
#define p putchar(' ')
#define l puts("");

int s;
char r[11];

void p0(char c) {
	p;
	for (int t = s; t--;) putchar(c != '1'&&c != '4' ? '-' : ' ');
	p;
}

void p1(char c) {
	putchar(c != '7'&&c != '1'&&c != '2'&&c != '3' ? '|' : ' ');
	q
	putchar(c != '5'&&c != '6' ? '|' : ' ');
}

void p2(char c) {
	p;
	for (int t = s; t--;) putchar(c != '1'&&c != '7'&&c != '0' ? '-' : ' ');
	p;
}

void p3(char c) {
	putchar(c != '2'&&c != '6'&&c != '8'&&c != '0' ? ' ' : '|');
	q
	putchar(c != '2' ? '|' : ' ');
}

void p4(char c) {
	p;
	for (int t = s; t--;) putchar(c != '1'&&c != '7'&&c != '4' ? '-' : ' ');
	p;
}

int main() {
	scanf("%d ", &s);
	gets(r);
	for (int i = 0; r[i]; i++) p0(r[i]), p;
	l
	for (int i = 0; i < s; i++) {
		for (int j = 0; r[j]; j++) p1(r[j]), p;
		l
	}
	for (int i = 0; r[i]; i++) p2(r[i]), p;
	l
	for (int i = 0; i < s; i++) {
		for (int j = 0; r[j]; j++) p3(r[j]), p;
		l
	}
	for (int i = 0; r[i]; i++) p4(r[i]), p;
}