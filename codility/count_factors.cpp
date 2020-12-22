#include <iostream>

using namespace std;

// N : 1 ~ 2,147,483,647
// 10^9 => square
int solution(int N) {
    int ans = 0;

    // 1 => 1
    if (N == 1) return 1;

    long long LN = N;

    // skip 1, ans self
    ans += 2;

    for (long long i = 2; i * i <= LN; ++i) {
        if (LN % i == 0) ans += 2;
        if (i * i == LN) ans -= 1;
    }

    return ans;
}

int main() {

    int N = 24;

    cout << solution(N) << endl;

    return 0;
}

// previous
// https://app.codility.com/demo/results/trainingVAGPY8-Z4H/