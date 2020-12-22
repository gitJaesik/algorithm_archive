#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B) {
    vector<int> ans;

    int MAX_L = 500002;

    long long pow_of_two[31];
    pow_of_two[0] = 1;
    for (int i = 1; i < 31; ++i) {
        pow_of_two[i] = pow_of_two[i-1] * 2;
    }

    int fibo[MAX_L];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < MAX_L; ++i) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] = fibo[i] % pow_of_two[30];
    }

    // 2 ^ 30 = 1073741824 // integer
    int N = A.size();
    for (int i = 0; i < N; ++i) {
        ans.push_back(fibo[A[i] + 1] % pow_of_two[B[i]]);
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
