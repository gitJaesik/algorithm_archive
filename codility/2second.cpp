#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// O(N**2) : timeout
// O(N Log(N) ): ok

int go(vector<int>& A, int curPos, int remains, int total) {
    if (remains == 0) {
        if (total % 2 == 1) return -1;
        else return total;
    }

    int ret = -1;

    if (curPos + 1 < A.size()) {
        int retUseCur = go(A, curPos + 1, remains -1, total + A[curPos + 1]);
        ret = max(ret, retUseCur);
        int retUnuseCur = go(A, curPos + 1, remains, total);
        ret = max(ret, retUnuseCur );
    }

    return ret;
}

int solution(vector<int> &A, int K) {
    int ans = -1;

    int N = A.size();
    sort(A.rbegin(), A.rend());

    // use zero or not
    ans = max(ans, go(A, 0, K-1, 0 + A[0]));
    ans = max(ans, go(A, 0, K, 0));

    return ans;
}


int main() {
    vector<int> A{4, 9, 8, 2, 6};
    int K = 3;

    cout << solution(A, K) << endl;

    return 0;
}