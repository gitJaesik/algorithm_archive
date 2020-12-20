#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0 - N - 1
// A[k] >= 0
// N : 0 ~ 100,000
// A[i] : 0 ~ 2,147,483,647
// -1 if ans > 10,000,000

//          --
//       ------------
//           -----
//              --
//           ----------------
//                  .


//       ------------
//          --
//           ----------------
//           -----
//              --
//                  .

bool cs(pair<long long, long long> lhs, pair<long long, long long> rhs) {
    if (lhs.first < rhs.first) return true;
    else if (lhs.first == rhs.first && lhs.second > rhs.second) return true;
    return false;
}

int solution(vector<int>& A) {

    int N = A.size();

    vector<pair<long long, long long>> bar;

    // make bar
    for (long long i = 0; i < N; ++i) {
        bar.push_back(make_pair(i - A[i], i + A[i]));
    }

    sort(bar.begin(), bar.end(), cs);

    // for (const auto& ba : bar) {
    //     cout << ba.first << " : " << ba.second << endl;
    // }

    int ans = 0;
    for (int i = 0; i < bar.size() -1; ++i) {
        for (int j = i + 1; j < bar.size(); ++j) {
            if (bar[i].second < bar[j].first) break;
            ans += 1;
        }
        if (ans > 10000000) return -1;
    }
    // O(n^2)
    // O(n log n)
    // O(n)

    return ans;
}

int main() {

    vector<int> A{1, 5, 2, 1, 4, 0};
    cout << solution(A) << endl;

    return 0;
}