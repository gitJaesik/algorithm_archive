#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// N : 1 ~ 100,000
// algorithm : stack
// O(N)
int solution(string &S, vector<int> &C) {
    // if (i == 1); return 0
    int ans = 0;


    char prevChar = S[0];
    int prevCost = C[0];
    for (int i = 1; i < S.length(); ++i) {
        if (S[i] == prevChar) {
            ans += min(C[i], prevCost);
            // equal
            // prevChar = prevChar;

            // prevCost
            prevCost = max(C[i], prevCost);
        } else {
            prevChar = S[i];
            prevCost = C[i];
        }
    }

    return ans;
}


int main() {
    string S = "abccbd";
    vector<int> C{0, 1, 2, 3, 4, 5};

    cout << solution(S, C) << endl;

    return 0;
}
