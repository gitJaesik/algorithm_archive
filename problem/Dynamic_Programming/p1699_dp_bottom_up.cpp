#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int d[100001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		d[i] = i;

		for (int j = 1; j <= floor(sqrt(i)); j++) {
			d[i] = min(d[i - j*j] + 1, d[i]);
		}
	}

	cout << d[n] << '\n';
	return 0;
}