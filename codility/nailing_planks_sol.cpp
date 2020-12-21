#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinIndex(int plank_start, int plank_end, vector<pair<int, int>> &sorted_nails, int ans) {

    int start = 0;
    int end = sorted_nails.size() - 1;
    int nail_idx = -1;
    while(start <= end) {
        int mid = (start + end) / 2;

        if (sorted_nails[mid].first < plank_start) {
            start = mid + 1;
        } else if (sorted_nails[mid].first > plank_end) {
            end = mid - 1;
        } else {
            end = mid - 1;
            nail_idx = mid;
        }
    }
    if (nail_idx == -1) return -1;

    int min_idx = sorted_nails[nail_idx].second;

    while(nail_idx < sorted_nails.size()) {
        if (sorted_nails[nail_idx].first > plank_end ) break;
        min_idx = min(min_idx, sorted_nails[nail_idx].second);
        if (min_idx <= ans) return ans;
        
        nail_idx += 1;
    }

    return min_idx;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int N = A.size();
    int M = C.size();

    vector<pair<int, int>> sorted_nails;
    for (int i = 0; i < M; ++i) {
        sorted_nails.push_back(make_pair(C[i], i));
    }
    sort(sorted_nails.begin(), sorted_nails.end());
    // for (const auto& el : sortedNails) {
    //     cout << el.first << endl;
    // }

    int ans = -1;

    for (int i = 0; i < N; ++i) {
        int ret = getMinIndex(A[i], B[i], sorted_nails, ans);
        if (ret == -1) return -1;
        ans = max(ans, ret);
    }

    return ans + 1;
}

int main() {

    vector<int> A{1, 4, 5, 8};
    vector<int> B{4, 5, 9, 10};
    vector<int> C{4, 6, 7, 10, 2};

    cout << solution(A, B, C) << endl;
    return 0;
}