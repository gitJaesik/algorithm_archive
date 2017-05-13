#include <iostream>
#include <cstring>

using namespace std;

long long d[110];

int main() {

	memset(d, 0, sizeof(d));
	
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;

	for (int i = 4; i < 109; ++i) {
		d[i] = d[i - 3] + d[i - 2];
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		cout << d[n] << endl;
	}

	return 0;
}