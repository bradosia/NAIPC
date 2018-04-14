#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
typedef long long i64;
using namespace std;
int n, n1, q, i, j, k, h1, h2, pk, mi, dh[5], dr[5], di[5];
i64 t, k1, k2, d1, d2, d3, max1, max2, d[5];
vector<pair<i64, i64> > v;
std::map<std::pair<int, int>, i64> c1, c2, m2;
std::map<std::pair<int, int>, int> p1, p2;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> q;
	// store house coordinates
	for (i = 0; i < n; i++)
		cin >> k1 >> k2, v.push_back(make_pair(k1, k2));
	// calculations
	n1 = n;
	for (j = 1; j < n; j++, n1--) {
		for (i = 1; i < n1; i++) {
			if (j == 1) {
				max1 = max(abs(v[i - 1].first - v[i].first),
						abs(v[i - 1].second - v[i].second));
				max2 = 0;
				c1[make_pair(j, i)] = max1;
				p1[make_pair(j, i)] = i;
				c2[make_pair(j, i)] = m2[make_pair(i, i + 1)] = max2;
				p2[make_pair(j, i)] = -1;
			} else if (j == 2) {
				d[0] = c1[make_pair(j - 1, i)];
				d[1] = c1[make_pair(j - 1, i + 1)];
				d[2] = max(abs(v[i - 1].first - v[i - 1 + j].first),
						abs(v[i - 1].second - v[i - 1 + j].second));
				for (k = 0; k < 3; k++) {
					di[k] = d[k];
					dr[k] = k;
					//cout << dh[k] << ":" << d[k] << "  ";
				}
				sort(dr, dr + 3,
						[&di](size_t i1, size_t i2) {return di[i1] > di[i2];});
				max1 = c1[make_pair(j, i)] = di[dr[0]];
				if (dr[0] == 2 && dr[1] == 0) {
					p1[make_pair(j, i)] = i;
					p2[make_pair(j, i)] = i + 2;
				} else if (dr[0] == 0 && dr[1] == 2) {
					p1[make_pair(j, i)] = i;
					p2[make_pair(j, i)] = i + 1;
				} else if (dr[0] == 0 && dr[1] == 1) {
					p1[make_pair(j, i)] = i + 1;
					p2[make_pair(j, i)] = i + 2;
				} else if (dr[0] == 1 && dr[1] == 0) {
					p1[make_pair(j, i)] = i + 1;
					p2[make_pair(j, i)] = i;
				} else if (dr[0] == 1 && dr[1] == 2) {
					p1[make_pair(j, i)] = i + 2;
					p2[make_pair(j, i)] = i;
				} else if (dr[0] == 2 && dr[1] == 1) {
					p1[make_pair(j, i)] = i + 2;
					p2[make_pair(j, i)] = i + 1;
				}
				max2 = c2[make_pair(j, i)] = m2[make_pair(i, i + j)] =
						di[dr[2]];
			} else {
				d[0] = c1[make_pair(j - 1, i)];
				d[1] = c1[make_pair(j - 1, i + 1)];
				d[2] = max(abs(v[i - 1].first - v[i - 1 + j].first),
						abs(v[i - 1].second - v[i - 1 + j].second));
				d[3] = c2[make_pair(j - 1, i)];
				d[4] = c2[make_pair(j - 1, i + 1)];
				dh[0] = p1[make_pair(j - 1, i)];
				dh[1] = p1[make_pair(j - 1, i + 1)];
				dh[2] = i + j;
				dh[3] = p2[make_pair(j - 1, i)];
				dh[4] = p2[make_pair(j - 1, i + 1)];
				//cout << "compare: ";
				for (k = 0; k < 5; k++) {
					di[k] = d[k];
					dr[k] = k;
					//cout << dh[k] << ":" << d[k] << "  ";
				}
				//cout << endl;
				sort(dr, dr + 5,
						[&di](size_t i1, size_t i2) {return di[i1] > di[i2];});
				/*cout << "indx ";
				 for (k = 0; k < 5; k++) {
				 cout << dr[k] << " ";
				 }
				 cout << endl;*/
				max1 = c1[make_pair(j, i)] = di[dr[0]];
				pk = p1[make_pair(j, i)] = dh[dr[0]];
				for (k = 1; k < 5; k++) {
					if (pk != dh[dr[k]]) {
						max2 = c2[make_pair(j, i)] = m2[make_pair(i, i + j)] =
								di[dr[k]];
						p2[make_pair(j, i)] = dh[dr[k]];
						break;
					}
				}
			}
			//cout << "c" << j << "," << i << ": " << max1 << " " << max2 << endl;
		}
	}
// print
	for (i = 0; i < q; i++) {
		cin >> h1 >> h2;
		if (abs(h1 - h2) == 1) {
			// two points
			cout << 0 << endl;
		} else {
			cout << m2[make_pair(h1, h2)] << endl;
		}
	}
	return 0;
}
