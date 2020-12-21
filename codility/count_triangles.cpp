#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int ans = 0;

    int N = A.size();
    sort(A.begin(), A.end());

    // O(n^3)
    /*
    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N -1; ++j) {
            for (int k = j + 1; k < N; ++k) {
                if (A[i] + A[j] > A[k] && A[j] + A[k] > A[i] &&
                    A[k] + A[i] > A[j]) {
                    ans += 1;
                }

            }
        }
    }
    */
    // https://app.codility.com/demo/results/trainingDV4RA4-FW7/

    // 말로 쓰자
    // A[P], A[Q], A[R]
    // A[P] + A[Q] > A[R]

    // O(n^3)
    // for (int i = 0; i < N - 2; ++i) {
    //     for (int j = i + 1; j < N - 1; ++j) {
    //         for (int k = j + 1; k < N; ++k) {
    //             if (A[i] + A[j] <= A[k]) {
    //                 break;
    //             }
    //             ans += 1;
    //         }
    //     }
    // }
    // https://app.codility.com/demo/results/training5UH2P9-QTF/

    for (int i = N - 1; i >= 1; --i) {
        int start = 0;
        int end = i - 1;
        while (start < end) {
            if (A[start] + A[end] > A[i]) {
                ans += end - start;
                end -= 1;
            } else {
                start += 1;
            }
        }
    }

    return ans;
}

int main() {

    vector<int> A{10, 2, 5, 1, 8, 12};
    cout << solution(A) << endl;

    return 0;
}