#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getBlockNum(int mid, vector<int> &A) {

    int curSum = 0;
    int blockNum = 1;

    for (const auto& a: A) {
        if (curSum + a > mid) {
            curSum = a;
            blockNum += 1;
        } else {
            curSum += a;
        }
    }

    return blockNum;
}

int solution(int K, int M, vector<int> &A){

    int lowerBound = 0;
    for_each(A.begin(), A.end(), [&](int el) { lowerBound = max(el, lowerBound); });
    int upperBound = 0;
    for_each(A.begin(), A.end(), [&](int el) { upperBound += el; });

    int ans = 0;
    while (lowerBound <= upperBound) {
        int mid = (lowerBound  + upperBound) / 2;
        int blockNum = getBlockNum(mid, A);
        if (blockNum <= K) {
            upperBound = mid - 1;
            ans = mid;
        } else {
            lowerBound = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> A{ 2, 1, 5, 1, 2, 2, 2};
    cout << solution(3, 5, A) << endl;
    return 0;
}