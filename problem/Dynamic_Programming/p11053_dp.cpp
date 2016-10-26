#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int d[1001];
int a[1001];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	memset(d, 0, sizeof(d));

	d[0] = 1;
	for (int i = 1; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}
	cout << ans << '\n';
	return 0;

}

// 가장 긴 증가하는 수열
// https://www.acmicpc.net/problem/11053
