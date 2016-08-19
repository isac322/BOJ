#include <cstdio>

using namespace std;

const int arr[] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

char str[9];

int get() {
	switch (str[0]) {
		case 'b':
			switch (str[1]) {
				case 'l':
					if (str[2] == 'a') return 0;
					else return 6;
				case 'r':
					return 1;
			}
		case 'r': return 2;
		case 'o': return 3;
		case 'y': return 4;
		case 'g':
			if (str[3] == 'y') return 8;
			else return 5;
		case 'v': return 7;
		case 'w': return 9;
	}
}

int main() {

	gets(str);
	long long a = get();
	gets(str);
	a = a * 10 + get();
	gets(str);
	printf("%lld", a*arr[get()]);
}