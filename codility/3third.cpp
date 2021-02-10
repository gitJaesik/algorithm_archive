#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    int ans = 100001;

    int N = A.size();
    int MAX_N = 100001;

    // actually C is not need
    // vector<int>C(A.begin(), A.end());

    vector<int> cnt(MAX_N + 1, 0);

    // O(N)
    for (int i = 0; i < N; ++i) {
        // C[i] = max(C[i], B[i]);
        cnt[max(A[i], B[i])] += 1;
    }

    for (int i = 1; i <= MAX_N; ++i) {
        if (cnt[i] == 0) {
            ans = i;
            break;
        }
    }

    return ans;
}


int main() {
    vector<int> A{ 1, 2, 4, 3};
    vector<int> B {1, 3, 2, 3};
    cout << solution(A, B) << endl;

    return 0;
}