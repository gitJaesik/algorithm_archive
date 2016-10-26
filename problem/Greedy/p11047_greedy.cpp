#include <iostream>

using namespace std;

int a[11];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int ans = 0;
	int index = n - 1;
	int kk = k;
	while (kk != 0) {
		ans += kk / a[index];
		kk %= a[index];
		index -= 1;
	}

	cout << ans << '\n';

	return 0;
}