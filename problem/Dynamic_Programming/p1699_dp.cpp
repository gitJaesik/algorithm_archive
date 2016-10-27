#include <iostream>
#include <cmath>
#include <algorithm>
#include <memory.h>

using namespace std;

// d[i] : i가 가질 수 있는는 제곱수 항의 최소 갯수
int d[100001];

const int inf = 1000000;

int go(int n) {
	int& ret = d[n];
	if (ret != -1) {
		return ret;
	}

	if (n == 0) {
		ret = 0;
		return ret;
	}

	ret = inf;

	for (int i = 1; i <= floor(sqrt(n)); i++) {
		ret = min(go(n - i*i) + 1, ret);
	}

	return ret;
}

int main() {

	int n;
	cin >> n;

	memset(d, -1, sizeof(d));


	cout << go(n) << '\n';

	return 0;
}