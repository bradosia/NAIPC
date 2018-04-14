#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, i, j, temp, k;
vector<int> v, v2;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	// set up remaining vector
	for (i = 1; i <= n; i++) {
		if (find(v.begin(), v.end(), i) == v.end()) {
			v2.push_back(i);
		}
	}
	i = j = 0;
	k = 0;

	while (k < n) {
		if (i >= v.size() && j < v2.size()) {
			cout << v2[j] << endl;
			j++;
			k++;
		} else if (j >= v2.size() && i < v.size()) {
			cout << v[i] << endl;
			i++;
			k++;
		} else if (v[i] < v2[j]) {
			cout << v[i] << endl;
			i++;
			k++;
		} else if (v[i] > v2[j]) {
			cout << v2[j] << endl;
			j++;
			k++;
		}
	}
	return 0;
}
