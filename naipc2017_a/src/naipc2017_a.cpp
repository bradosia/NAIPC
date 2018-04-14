#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
string temp;
int l[301], r[301], v[301], w[301], m[301][300 * 300], n, i, j, lp, rp, wx,
		maxv;

int main() {
	wx = 300 * 300;
	cin >> n;
	cin.ignore();
	for (i = 1; i < n + 1; i++) {
		getline(cin, temp);
		lp = 0;
		rp = 0;
		for (char& c : temp) {
			if (c == '(') {
				lp++;
			} else {
				if (lp > 0)
					lp--;
				else
					rp++;
			}
		}
		v[i] = 0;
		if (lp - rp != 0) {
			v[i] = temp.length();
		}
		l[i] = lp;
		r[i] = rp;
		w[i] = (lp - rp);
	}
	cout << endl << setw(5) << "left" << setw(6) << "right" << setw(7)
			<< "weight" << setw(7) << "length" << endl;
	for (i = 1; i < n + 1; i++) {
		cout << setw(5) << l[i] << setw(6) << r[i] << setw(7) << w[i] << setw(7)
				<< v[i] << endl;
	}

	for (i = 0; i < wx; i++) {
		m[0][i] = 0;
	}

	for (i = 1; i < n + 1; i++) {
		for (j = -4500; j < 4500; j++) {
			if (w[i] > j) {
				m[i][j + 4500] = m[i - 1][j + 4500];
			} else {
				m[i][j + 4500] = max(m[i - 1][j + 4500],
						m[i - 1][j + 4500 - w[i]] + v[i]);
			}
		}
	}

	cout << endl;
	for (i = 0; i < n + 1; i++) {
		for (j = 4490; j < 4510; j++) {
			cout << setw(3) << m[i][j];
		}
		cout << endl;
	}
	cout << endl;

	maxv = 0;
	for (i = 0; i < n + 1; i++) {
		maxv = max(maxv, m[i][4500]);
	}

	cout << maxv;

	return 0;
}
