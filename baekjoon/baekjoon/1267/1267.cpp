#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    scanf("%d", &n);
    
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        a += (t / 30 + 1) * 10;
        b += (t / 60 + 1) * 15;
    }
    
    if (a == b) printf("Y M %d", a);
    else if (a < b) printf("Y %d", a);
    else printf("M %d", b);
}