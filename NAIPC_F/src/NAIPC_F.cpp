#include <iostream>
#include <iomanip>
#include <algorithm>    // std::next_permutation, std::sort
#include <cmath>
using namespace std;
int n, m, i, g, w[2000], j, k;
double p, pp[2000], ans, ppp, pppp, p_l;

int main() {
	cin >> n >> m;
	g = n + m - 1;
	/* set up win and loss permutation array
	 * 1 = loss (L)
	 * 0 = win (W)
	 * n,m = 3,2
	 * w[] = {1,1,1,1}
	 * */
	for (i = 0; i < g; i++) {
		cin >> pp[i];
		w[i] = 1;
	}
	/* w[] = {0,1,1,1}
	 * */
	for (i = 0; i < (m - 1); i++) {
		w[i] = 0;
	}
	/* n,m = 3,2
	 *
	 * W:L
	 * 2:0 = P(WW)
	 * 2:1 = P(LWW) + P(LWW)
	 * 2:2 = P(LLWW) + P(LWLW) + P(WLLW)
	 * */
	ans = 0;
	for (i = 0; i < n; i++) {
		pppp = 0;
		k = i + m - 1;
		p_l = pp[k];
		if (p_l > 0) {
			do {
				ppp = 1;
				for (j = 0; j < k; j++) {
					if (w[j] == 0) {
						ppp *= pp[j];
					} else {
						ppp *= 1 - pp[j];
					}
				}
				pppp += ppp;
			} while (std::next_permutation(w, w + i + 1));
			pppp *= pow(pp[k], i + 1);
			ans += pppp;
		}
	}
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}
