#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N : 0 ~ 100,000

int fibo[100];


int fibonacci(int M) {

    int& cache = fibo[M];

    if (cache != -1) {
        return cache;
    }

    if (M == 0) {
        cache = 0;
        return cache;
    }
    else if (M == 1) {
        cache = 1;
        return cache ;
    }

    cache = fibonacci(M-1) + fibonacci(M-2);
    return cache ;
}

int go(vector<int>& A, int K, int curPosition) {

    if (curPosition == A.size()) return 0;

    int ans = 100001;
    for (int i = K; i >= 1; --i) {
        if (curPosition + fibonacci(i) > A.size()) continue;
        if (curPosition + fibonacci(i) ==  A.size() || A[curPosition + fibonacci(i)] == 1) {
            ans = min(ans, go(A, K, curPosition + fibonacci(i)) + 1);
        }
    }
    return ans;
}

int solution(vector<int> &A) {

    for (int i = 0; i < 100; ++i) {
        fibo[i] = -1;
    }

    for (int i = 0; ; i++) {
        if (fibonacci(i) > 100000) {
            break;
        }
    }

    // combination from -1 to N
    int ans = 100001;

    int distance = A.size() + 2;

    int K = 0;
    while (true) {
        if (fibonacci(K) > distance) {
            K -= 1;
            break;
        }
        K += 1;
    }

    // brute force
    ans = min(ans, go(A, K, -1));

    if (ans == 100001) ans = -1;

    return ans;
}

int main() {

    vector<int> A{0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0};

    cout << solution(A) << endl;

    return 0;
}