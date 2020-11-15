#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {

    int M = -1;
    int S = 0;

    for (size_t i = 0; i < A.size(); i++) {
        if (A[i] < 0) A[i] = A[i] * -1;
        M = max(M, A[i]);
        S = S + A[i];
    }

    vector<int> count(M + 1, 0);

    for (size_t i = 0; i < A.size(); i++) {
        count[A[i]] += 1;
    }

    vector<int> dp(S + 1, -1);

    // 0 is alway possible
    dp[0] = 0;

    for (int i = 1; i < M + 1; i++) {

        // if element i is exist, get the combination
        if (count[i] > 0) {
            for (int j = 0; j < S + 1; j++) {

                // have sub already, add it's count for combination
                if (dp[j] >= 0) {
                    dp[j] = count[i];

                // if new combination is made
                }else if (j >= i && dp[j-i] > 0) {
                    // get new combination
                    dp[j] = dp[j-i] - 1;
                }
            }
        }
    }

    int ans = S;

    for (int i = 1; i < S / 2 + 1; i++) {
        if (dp[i] >= 0) {
            ans = min(ans, S - i * 2);
        }
    }


    return ans;
}


int main()
{
    vector<int> A {1, 5, 2, -2};
    cout << solution(A) << endl;;

    return 0;
}
