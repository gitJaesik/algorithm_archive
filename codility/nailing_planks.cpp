#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
N and M are integers within the range [1..30,000];
each element of arrays A, B, C is an integer within the range [1..2*M];
A[K] ≤ B[K].
*/

// return  2, 1, 0
// insert sort
int findNail(int a, int b, vector<int> &C, int j) {

}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    vector<int> sortedVector;

    for (int i = 0; i < C.size(); ++i) {
        vector<int>::iterator it = upper_bound(sortedVector.begin(), sortedVector.end(), C[i]);
        sortedVector.insert(it, C[i]);

        for (const auto& el: sortedVector) {
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}

int main() {

    vector<int> A{1, 4, 5, 8};
    vector<int> B{4, 5, 9, 10};
    vector<int> C{4, 6, 7, 10, 2};

    cout << solution(A, B, C) << endl;

    return 0;
}