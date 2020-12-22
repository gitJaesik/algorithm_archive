#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B) {
    vector<int> ans;

    int MAX_L = 500002;

    // long long fibo[MAX_L];
    // fibo[0] = 0;
    // fibo[1] = 1;
    // for (int i = 2; i < MAX_L; ++i) {
    //     fibo[i] = fibo[i - 1] + fibo[i - 2];
    // }

    long long pow_of_two[31];
    pow_of_two[0] = 1;
    for (int i = 1; i < 31; ++i) {
        pow_of_two[i] = pow_of_two[i-1] * 2;
    }

    // 2 ^ 30 = 1073741824 // integer
    int N = A.size();
    for (int i = 0; i < N; ++i) {
        // zero base
        long long long_ans = 0;
        long long long_ans_prev = 1;
        long long long_ans_before_prev = 0;
        for (int j = 1; j <= A[i]; ++j) {
            long_ans = ((long_ans_prev % pow_of_two[B[i]]) + (long_ans_before_prev % pow_of_two[B[i]])) % pow_of_two[B[i]];
            long_ans_before_prev = long_ans_prev % pow_of_two[B[i]];
            long_ans_prev = long_ans % pow_of_two[B[i]];
        }

        //  fibo[A[i] + 1] % pow_of_two[B[i]];
        int int_ans = long_ans;
        ans.push_back(int_ans);
    }
    // https://app.codility.com/demo/results/trainingM7ZWC8-8X8/

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
