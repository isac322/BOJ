#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, arr[1'000'000], b, c;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i) scanf("%i", arr + i);
    scanf("%i%i", &b, &c);
    
    long long tot = 0;
    for (int i = 0; i < n; ++i) {
        const lldiv_t &div1 = div(max(0ll, static_cast<long long>(arr[i] - b)), static_cast<long long>(c));
        tot += div1.quot + (div1.rem ? 1 : 0);
    }
    printf("%lli\n", tot + n);
}