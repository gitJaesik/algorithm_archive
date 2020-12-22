#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B) {
    vector<int> ans;

    int MAX_L = 500001;

    int fibo[MAX_L];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < MAX_L; ++i) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    // 2 ^ 30 = 1073741824 // integer
    int N = A.size();
    for (int i = 0; i < N; ++i) {
        // zero base
        ans.push_back(fibo[A[i] + 1] % (int)(pow(2, B[i])));
    }

    return ans;
}

int main() {
    vector<int> A{4, 4, 5, 5, 1};
    vector<int> B{3, 2, 4, 3, 1};
    vector<int> ans = solution(A, B);

    for (const auto& an : ans) {
        cout << an << endl;
    }
    return 0;
}
