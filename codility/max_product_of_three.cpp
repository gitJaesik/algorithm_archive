#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());

    int len = A.size();

    int ans = max(A[0] * A[1] * A[len-1], A[len-1] * A[len-2] * A[len-3]);

    return ans;
}

int main() {
    vector<int> A{-3, 1, 2, -2, 5, 6};
    cout << solution(A) << endl;
    return 0;
}