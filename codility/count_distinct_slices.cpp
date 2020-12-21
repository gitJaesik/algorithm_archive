#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

// 1000000000
// 705082704
using namespace std;

int solution(int M, vector<int> &A) {

    int N = A.size();
    unordered_map<int, int> h;

    int front = 0;

    int ans = 0;
    int total = 0;

    for (int back = 0; back < N; ++back) {
        while (front < N) {
            // 이미 존재하는 경우 / non distinct
            if (h.find(A[front]) != h.end()) {
                break;
            }
            else {
                h[A[front]] = 1;
                front +=1;
                total +=1;
            }
        }

        ans += total;
        h.erase(A[back]);
        total -= 1;
        if (ans > 1000000000) return 1000000000;
    }

    return ans;
}


int main() {

    // vector<int> A {3, 4, 5, 5, 2};
    // vector<int> A {1, 2, 1, 2, 1};
    /*
    1,
    1, 2,
    2,
    2, 1,
    1,
    1, 2,
    2,
    2, 1,
    1
    */
    vector<int> A {1, 2, 1, 2};
    /*
    1,
    1, 2,
    2,
    2, 1,
    1,
    1, 2,
    2,
    */


    cout << solution(6, A) << endl;

    return 0;
}

// https://app.codility.com/demo/results/training2QMHZA-HJG/