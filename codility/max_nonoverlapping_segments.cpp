#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A, vector<int> &B)
{
    int ans = 0;
    size_t N = A.size();

    int lastEndPoint = -1;

    for (size_t i = 0; i < N; i++) {
        if (lastEndPoint < A[i]) {
            ans += 1;
            lastEndPoint = B[i];
        }
    }

    return ans;
}



int main() {

    vector<int> A{1, 3, 7, 9, 9};
    vector<int> B{5, 6, 8, 9, 10};
    cout << solution(A, B) << endl;

    return 0;
}