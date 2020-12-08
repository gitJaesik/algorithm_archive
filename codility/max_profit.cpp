#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N is an integer within the range [0..400,000];
// O(n^2) = 160,000,000,000
// each element of array A is an integer within the range[0..200, 000].

int solution(vector<int> &A) {
    // ans = max(d[i][j])
    // 한번에 끝내자
    // d[i] d[j]

    // i
    // 현재까지 최고 차이 값 : ans
    // 현재까지 제일 적은 값 : m
    // A[i]의 값 - m 이 ans보다 높으면 ans = A[i] - m
    // A[i]의 값이 m의 값보다 적으면 m = min(A[i], m)

    int ans = 0;
    int m = 200001;
    for (int i = 0; i < A.size(); ++i) {
        m = min(A[i], m);
        ans = max(A[i] - m, ans);
    }

    return ans;
}

int main() {

    vector<int> A{23171, 21011, 21123, 21366, 21013, 21367};
    cout << solution(A) << endl;
    return 0;
}
