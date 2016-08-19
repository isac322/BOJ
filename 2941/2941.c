#include <stdio.h>

char s[105];
int l = 0;
int v(int p) {
	if (p>=l) return 0;
	char t = s[p];
	if (t=='c')return v(s[p+1] == '=' || s[p+1] == '-' ? p+2 : p+1) + 1;
	else if (t=='d')if (s[p+1] == 'z' && s[p+2] == '=') return v(p+3) + 1;
	else if (s[p+1]=='-') return v(p+2) + 1;
	else return v(p+1) + 1;
	else if (t=='l' | t=='n')return v(s[p+1] == 'j' ? p+2 : p+1) + 1;
	else if (t=='s' | t=='z')return v(s[p+1] == '=' ? p+2 : p+1) + 1;
	else return v(p+1) + 1;
}
int main() {
	while ((s[l]=getchar()) != '\n' && s[l] != -1) l++;
	printf("%d", v(0));
}