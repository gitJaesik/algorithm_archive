#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {

    vector<int> maxSliceLeft(A.size());
    vector<int> maxSliceRight(A.size());

    for (int i = 1; i < A.size() - 1; i++) {
        maxSliceLeft[i] = A[i] + maxSliceLeft[i - 1];
        maxSliceLeft[i] = max(maxSliceLeft[i], 0);
    }

    for (int i = A.size() - 2; i >= 1; i--) {
        maxSliceRight[i] = A[i] + maxSliceRight[i + 1];
        maxSliceRight[i] = max(maxSliceRight[i], 0);
    }

    int ans = 0;
    for (int i = 1; i < A.size() - 1; i++)  {
        int sum = maxSliceLeft[i-1] + maxSliceRight[i+1];
        ans = max(ans, sum);
    }
    return ans;
}

int main() {

    vector<int> A {3, 2, 6, -1, 4, 5, -1, 2};

    cout << solution(A) << endl;

    return 0;
}
