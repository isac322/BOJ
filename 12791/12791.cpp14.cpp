#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int q, s, e;
	scanf("%d", &q);

	int years[] = { 1967,1969,1970,1971,1972,1973,1973,1974,1975,1976,1977,1977,1979,	1980,1983,1984,1987,1993,1995,1997,1999,2002,2003,2013,2016,9999 };
	char album[][51] = { "DavidBowie","SpaceOddity","TheManWhoSoldTheWorld","HunkyDory","TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars","AladdinSane","PinUps","DiamondDogs","YoungAmericans","StationToStation","Low","Heroes","Lodger","ScaryMonstersAndSuperCreeps","LetsDance","Tonight","NeverLetMeDown","BlackTieWhiteNoise","1.Outside","Earthling","Hours","Heathen","Reality","TheNextDay","BlackStar" };

	while (q--) {
		scanf("%d %d", &s, &e);
		int b = 0, l = 0;

		for (int i = 1; i < 26; i++) {
			if (s > years[i - 1] && s <= years[i]) b = i;
			if (e >= years[i - 1] && e < years[i]) l = i - 1;
		}

		if (years[l] > e) l = -1;
		if (b <= l) {
			printf("%d\n", l - b + 1);
			for (int i = b; i <= l; i++) {
				printf("%d %s\n", years[i], album[i]);
			}
		}
		else {
			puts("0");
		}
	}
}