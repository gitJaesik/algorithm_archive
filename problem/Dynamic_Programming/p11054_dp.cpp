// https://www.acmicpc.net/problem/11054
// 가장 긴 바이토닉 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void go(vector<int>& v, vector<int>& d) {
	for (int i = 0; i < v.size(); i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);

	vector<int> d1(n);
	vector<int> d2(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	vector<int> b(a);

	reverse(b.begin(), b.end());

	go(a, d1);
	go(b, d2);

	reverse(d2.begin(), d2.end());

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (ans < d1[i] + d2[i]) {
			ans = d1[i] + d2[i];
		}
	}

	cout << ans -1 << '\n';

	return 0;
}