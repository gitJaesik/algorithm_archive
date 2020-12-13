#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {

    int N = A.size();

    int ans = 2000000001;

    sort(A.begin(), A.end());

    int front = 0;
    int end = N - 1;

    while (true) {
        ans = min(ans, abs(A[front] + A[end]));
        if (front == end) break;
        if (abs(A[front]) > abs(A[end])) {
            front += 1;
        } else {
            end -= 1;
        }
        if (front >= N || end <= -1) break;
    }

    return ans;
}


int main() {

    vector<int> A{1, 4, -3};
    // vector<int> A{-8, 4, 5, -10, 3};
    cout << solution(A) << endl;

    return 0;
}

// https://app.codility.com/demo/results/trainingZ4NRNZ-396/
// https://app.codility.com/demo/results/trainingHEBSEE-NNF/