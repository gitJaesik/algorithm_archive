#include <iostream>

using namespace std;

// 10^9 => square
int solution(int N) {
    int ans = 0;

    // skip 1, ans self
    ans += 2;

    for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) ans += 2;
        if (i * i == N) ans -= 1;
    }

    return ans;
}

int main() {

    int N = 24;

    cout << solution(N) << endl;

    return 0;
}

