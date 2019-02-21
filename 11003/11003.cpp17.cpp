#include <iostream>
#include <unistd.h>
#include <deque>
#include <algorithm>

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
        *end++ = ' ';
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


int main() {
    typedef pair<int, int> PII;
    deque<PII> que;

    int n = FIO::readInt(), l = FIO::readInt(), a;

    for (int i = 0; i < n; i++) {
        a = FIO::readInt();

        while (not que.empty() and que.front().second <= i - l) que.pop_front();
        while (not que.empty() and que.back().first >= a) que.pop_back();
        que.emplace_back(a, i);

        FIO::printInt(que.front().first);
    }

    FIO::flush();
}