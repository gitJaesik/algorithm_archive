#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {

    int N = A.size();

    int ans = 2000000001;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            ans = min(ans, abs(A[i] + A[j]));
        }
    }

    return ans;
}


int main() {

    vector<int> A{1, 4, -3};
    // vector<int> A{-8, 4, 5, -10, 3};
    cout << solution(A) << endl;

    return 0;
}