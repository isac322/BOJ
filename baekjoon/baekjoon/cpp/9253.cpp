#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2, s3;
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);
	puts(s1.find(s3) != -1 && s2.find(s3) != -1 ? "YES" : "NO");
}