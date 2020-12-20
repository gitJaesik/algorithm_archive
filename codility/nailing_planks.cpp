#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
N and M are integers within the range [1..30,000];
each element of arrays A, B, C is an integer within the range [1..2*M];
A[K] ≤ B[K].
*/

// return  2, 1, 0
// insert sort

bool isNailed(vector<int> &A, vector<int> &B, vector<int> &C, int mid) {

    vector<bool> nailed(A.size(), false);

    for (int i = 0; i <= mid; ++i) {
        for (int j = 0; j < A.size(); ++j) {
            if ( C[i] >= A[j] && C[i] <= B[j]) nailed[j] = true;
        }
    }

    for (const auto& el: nailed) {
        if (el == false) return false;
    }
    return true;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int N = A.size();
    int M = C.size();

    int start = 0;
    int end = M -1;
    int ans = -1;

    while (start <= end) {
        int mid = end - start / 2;
        if (isNailed(A, B, C, mid) == true) {
            end = mid -1;
            ans = mid;
        } else {
            start = mid + 1;
        }

    }

    return ans + 1;
}

int main() {

    vector<int> A{1, 4, 5, 8};
    vector<int> B{4, 5, 9, 10};
    vector<int> C{4, 6, 7, 10, 2};

    cout << solution(A, B, C) << endl;

    return 0;
}