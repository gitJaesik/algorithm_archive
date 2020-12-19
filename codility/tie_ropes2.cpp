#include <iostream>
#include <vector>

using namespace std;

int solution(int K, vector<int> &A)
{
    int N = A.size();
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        if (sum >= K) {
            ans += 1;
            sum = 0;
        }
    }
    return ans;
}

int main () {
    vector<int> A {1, 2, 3, 4, 1, 1, 3};
    cout << solution(4, A) << endl;

    return 0;
}