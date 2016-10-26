#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

// d[i][k] : i번째 음료를 마시는 경우, 연속으로 k개를 마셨는지 확인하기
// d[i] : i번째를 마시는 경우와 안 마시는 경우 분석하기
// d[i][0] = max(d[i-2][0],d[i-2][1]) + d[i][0];
// d[i][1] = max(d[i-1][0]) + d[i][1];

int d[10001][3];	// 항상 d[i][k]의 최대값으로 구한다.
int a[10001];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	memset(d, 0, sizeof(0));

	d[0][0] = 0;
	d[0][1] = a[0];
	d[0][2] = 0;	// 2번째가 될 수 없다.

	for (int i = 1; i < n; i++) {
		d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	int ans = max(d[n-1][0], max(d[n-1][1], d[n-1][2]));

	cout << ans << '\n';

	return 0;
}