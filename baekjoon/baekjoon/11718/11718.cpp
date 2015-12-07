#include <cstdio>

int main() {
    char buf[101];
    while (~scanf("%[^\n]%*c", buf)) puts(buf);
}