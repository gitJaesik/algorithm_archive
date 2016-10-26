// https://www.acmicpc.net/problem/11055
// 가장 큰 증가 부분 수열

#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
int a[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	d[0] = a[0];

	for (int i = 1; i < n; i++) {
		d[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				d[i] = max(d[i], d[j] + a[i]);
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