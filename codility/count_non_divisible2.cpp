#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int>& A) {
    int N = A.size();
    vector<int> counts ( (*max_element(A.begin(), A.end())) + 1, 0 );

    for (int i = 0; i < N; ++i)  {
        counts[A[i]] += 1;
    }

    vector<int> ans(N, 0);
    for (int i = 0; i < N; ++i) {
        int divisors = 0;

        for (int j = 1; j * j <= A[i]; ++j) {
            if (A[i] % j == 0) {
                divisors += counts[j];

                if (A[i] / j != j) {
                    divisors += counts[A[i] / j];
                }
            }
        }

        ans[i] = N - divisors;
    }

    return ans;
}

int main()
{
    vector<int> A{3, 1, 2, 3, 6};
    vector<int> ans = solution(A);
    for (const auto &an : ans)
    {
        cout << an << endl;
    }

    return 0;
}