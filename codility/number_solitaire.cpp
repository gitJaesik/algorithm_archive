#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

size of A = N (2.. 100,000)
el of A (-10,000 ~ 10.000)
move (1 ~ 6)

ans = max sum el

A[0] + A[N-1] is default value

burte force
max (current + 1, current + 2, current + 3, current + 4, current + 5, current + 6)

cache
max sum sel from dp[point x]
ans = dp[0]
dp[]

*/

int dp[100001];

int go(int pos, int curSum, vector<int>& A, int N ) {

    if (pos == N - 1) {
        return A[pos];
    }

    if (dp[pos] != -2000000000) {
        return dp[pos];
    }

    int &ret = dp[pos];

    // dp[0] = max(go(pos + 1, curSum, N), go(pos + 2, curSum, N), go(pos + 3, curSum, N), go(pos + 4, curSum, N), go(pos + 5, curSum, N), go(pos + 6, curSum, N));

    int maxVal = -10000000001;
    for (int i = 1; i <= 6; ++i) {
        if (pos + i < N) maxVal = max(maxVal, go(pos + i, A[pos + i], A, N));
    }
    ret = maxVal + curSum;
    return ret;
}

int solution(vector<int> &A) {
    // initialize
    for (int i = 0; i <= 100000; ++i) { dp[i] = -2000000000; }

    go(0, A[0], A, A.size());

    return dp[0];
}

int main() {

    vector<int> A{1, -2, 0, 9, -1, -2};

    cout << solution(A) << endl;

    return 0;
}