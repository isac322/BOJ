#include <cstdio>
#include <random>

using namespace std;

int main() {
	random_device rd;
	uniform_int_distribution<> dist(0, 1);
	puts(dist(rd) ? "Yonsei" : "Korea");
}