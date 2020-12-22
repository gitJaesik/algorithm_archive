#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
    // if (K == 0) return A;
    // if (A.size() == 0) return A;

    // int sizeA = A.size();
    // if (K > sizeA) {
    //     K = K -sizeA;
    // }

    // std::rotate(A.rbegin(),A.rbegin()+K,A.rend());

    // return A;

    int N = A.size();

    if (K == 0) return A;
    if (N == 0) return A;

    if (K > N) {
        K = K % N;
    }

    rotate(A.rbegin(), A.rbegin() + K, A.rend());

    return A;
}

int main() {

    // A = [3, 8, 9, 7, 6]
    // K = 3

    vector<int> A  {3, 8, 9, 7, 6};
    int K = 3;
    vector<int> ans = solution(A, K);
    for (auto an : ans) {
        cout << an << endl;
    }

    return 0;
}