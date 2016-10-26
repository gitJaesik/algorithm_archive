#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int d[301][3];
int a[301];

int go(int n, int status) {
	int& ret = d[n][status];
	if (ret != -1) {
		return ret;
	}

	if (n == 0) {
		return 0;
	}

	ret = 0;

	if (status == 1) {
		if (n == 1) {
			ret = max(a[n], ret);
		}
		else if (n - 2 >= 0) {
			ret = max(go(n - 2, 1) + a[n], ret);
			ret = max(go(n - 2, 2) + a[n], ret);
		}
	}
	else {
		if (n - 1 >= 0) {
			ret = max(go(n - 1, 1) + a[n], ret);
		}
	}

	return ret;
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	int ans = 0;
	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	d[0][1] = 0;
	d[0][2] = 0;
	ans = go(n, 2);
	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	d[0][1] = 0;
	d[0][2] = 0;
	ans = max(ans, go(n, 1));

	cout << ans << '\n';

	return 0;
}