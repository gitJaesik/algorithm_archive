//https://www.acmicpc.net/problem/1783
// 문제 이해가 어려웠다.
// 칸은 모든 칸의 경우의 수가 아닌 건너띄지 않는 경우의 수다.
// 4번은 4의 배수마다 1,2,3,4번의 방법을 이용하는 것이아닌 딱 4번 사용할때만 모두 1번씩 사용하라는 것이다.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	int ans = 0;
	if (n == 1) ans = 1;
	else if (n == 2) ans = min(4, (m + 1) / 2);
	else if (m < 7) ans = min(4, m);
	else ans = m - 2;

	cout << ans << '\n';

	return 0;
}