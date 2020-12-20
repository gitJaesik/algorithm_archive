#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int M, vector<int> &A) {

    int N = A.size();
    unordered_map<int, int> h;

    int front = 0;

    int ans = 0;
    int total = 0;

    for (int back = 0; back < N; ++back) {
        while (front < N) {
            if (h.find(A[front]) != h.end()) {
                front -= 1;
                break;
            }
            h[A[front]] = 1;
            front +=1;
            total +=1;
        }

        ans += total;
        h.erase(A[back]);
        total -= 1;
    }

    return ans;
}


int main() {

    vector<int> A {3, 4, 5, 5, 2};
    cout << solution(6, A) << endl;

    return 0;
}