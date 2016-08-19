#include <stdio.h>

int main() {
	long long a, max, min;
	int sp, ep, cnt = 0, i, tmp;

	scanf("%lld", &a);
	max = min = a;
	for (sp = 0; sp < 64; sp++) if ((a >> sp) & 1) break;
	for (ep = sp; (max >> ep) & 1 && ep < 64; ep++, cnt++);
	max = max + (1LL << ep) - (1LL << (ep - 1));
	max = max >> ep;
	max = max << (ep - --cnt);
	for (i = 0; i < cnt; i++, max++) max = max << 1;
	while (1) {
		tmp = 0;
		for (i = 0; i < ep; i++) if ((max >> i) & 1) tmp++;
		if (tmp == cnt && max > a) break;
		max++;
	}

	if (!sp) {
		for (; !((min >> ep) & 1) && ep < 64; ep++);
		if (ep == 64) {
			min = 0;
			printf("%lld %lld", min, max);
			return 0;
		}
		min = min - (1LL << ep) + (1LL << (ep - 1));
		min = min >> (ep - 1);
		for (i = 0; i <= cnt; i++, min++) min = min << 1;
		min = min << (ep - cnt - 2);
		while (1) {
			tmp = 0;
			for (i = 0; i < ep - 1; i++) if ((min >> i) & 1) tmp++;
			if (tmp == cnt + 1 && min < a) break;
			min--;
		}
	} else min = min - (1LL << sp) + (1LL << (sp - 1));
	printf("%lld %lld", min, max);
}