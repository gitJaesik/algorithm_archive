#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int d[1001];
int a[1001];

int go(int n) {
	int& ret = d[n];
	if (ret != -1) {
		return ret;
	}

	if (n == 0) {
		return 0;
	}

	ret = 0;
	for (int i = 1; i <= n; i++) {
		ret = max(ret, go(n - i) + a[i]);
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	memset(d, -1, sizeof(d));

	cout << go(n) << '\n';

	return 0;
}