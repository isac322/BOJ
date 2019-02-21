#include <cstdio>
#include <algorithm>
#include <vector>
#include <unistd.h>

using namespace std;

namespace FIO {
    const size_t BUFFER_SIZE = 1048576;
    char buffer[BUFFER_SIZE];
    char *ptr = buffer + BUFFER_SIZE;

    inline char readByte() {
        if (ptr == buffer + BUFFER_SIZE) {
            syscall(0x00, 0, buffer, BUFFER_SIZE);
            ptr = buffer;
        }
        return *(ptr++);
    }

    int readInt() {
        unsigned ret = 0;
        unsigned char c = readByte();
        while (c <= ' ') {
            c = readByte();
        }
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = readByte();
        }
        while (c > ' ') {
            ret = ret * 10 + (c - '0');
            c = readByte();
        }
        return neg ? -(int) ret : (int) ret;
    }

    char outbuf[BUFFER_SIZE + 20];
    char *outp = outbuf;

    void printInt(int n) {
        unsigned nn;
        if (n < 0) nn = -n, *outp++ = '-';
        else nn = n;
        char *end = outp;
        do {
            *end++ = nn % 10 + '0';
            nn /= 10;
        } while (nn);
        reverse(outp, end);
        *end++ = '\n';
        if (end < outbuf + BUFFER_SIZE) outp = end;
        else {
            syscall(0x01, 1, outbuf, end - outbuf);
            outp = outbuf;
        }
    }

    void flush() {
        syscall(0x01, 1, outbuf, outp - outbuf);
    }
};

vector<int> pre[1000];
int btime[1000];
int dp[1000];

int solve(int v) {
    int &p = dp[v];
    if (p != -1) return p;
    p = 0;
    for (int q : pre[v]) p = max(p, solve(q));
    return p += btime[v];
}

int main() {
    int t = FIO::readInt(), k;
    int n, a, b, w;
    while (t--) {
        n = FIO::readInt();
        k = FIO::readInt();
        fill_n(dp, n, -1);

        for (int i = 0; i < n; i++) {
            pre[i].clear();
            btime[i] = FIO::readInt();
        }
        for (int i = 0; i < k; i++) {
            a = FIO::readInt();
            b = FIO::readInt();
            a--, b--;
            pre[b].emplace_back(a);
        }
        w = FIO::readInt();
        FIO::printInt(solve(--w));
    }

    FIO::flush();
}