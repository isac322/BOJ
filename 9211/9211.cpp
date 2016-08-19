#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<double, double> > army;

inline double sum(const vector<int> &vec) {
	double ret = 0.0;
	for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); i++) ret += army[*i].first;
	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	vector<int> inLink[100], outLink[100];
	double ratio[100][100];

	while (tc--) {
		army.clear();
		int n, l, t;
		scanf("%d%d%d", &n, &l, &t);
		army.resize(n);

		for (int i = 0; i < n; i++) {
			inLink[i].clear();
			outLink[i].clear();
			fill_n(ratio[i], n, 0.0);
			scanf("%lf", &army[i].first);
		}

		for (int i = 0; i < l; i++) {
			int a, b;
			double c;
			scanf("%d %d %lf", &a, &b, &c);

			outLink[a].push_back(b);
			inLink[b].push_back(a);

			ratio[a][b] = c;
		}

		for (int i = 0; i < t; i++) {
			for (int j = 0; j < n; ++j) {
				double mi = 0;
				for (vector<int>::iterator iter = outLink[j].begin(); iter != outLink[j].end(); iter++) {
					mi += ratio[j][*iter];
					army[*iter].second += army[j].first * ratio[j][*iter];
				}
				army[j].first *= (1.0 - mi);
			}

			for (int j = 0; j < n; ++j) {
				army[j].first += army[j].second;
				army[j].second = 0.0;
			}
		}

		double ret = sum(outLink[0]) + sum(inLink[0]) + army[0].first;
		for (int i = 1; i < n; i++) {
			ret = min(ret, sum(inLink[i]) + sum(outLink[i]) + army[i].first);
		}
		printf("%.9lf\n", ret);
	}
}