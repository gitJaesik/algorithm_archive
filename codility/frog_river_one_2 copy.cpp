#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> lhs, pair<int, int>  rhs) {
    if (lhs.first < rhs.first) return true;
    else if (lhs.first == rhs.first) {
        if (lhs.second > rhs.second) return true;
    }
    return false;
}

int solution(int X, vector<int> &A)
{
    vector<pair<int, int>> apair;
    for (size_t i = 0; i < A.size(); i++) {
        apair.push_back(make_pair( A[i], i));
    }

    sort(apair.begin(), apair.end(), cmp);
    // for (const auto &pair : apair)
    // {
    //     cout << pair.first << ", " << pair.second << endl;
    // }

    vector<int> ansArr(X + 1, -1);
    for (const auto &pair : apair)
    {
        ansArr[pair.first] = pair.second;
    }

    int ans = -1;

    for (int i = 1; i <= X; i++) {
        if (ansArr[i] == -1) return -1;
        ans = max(ans, ansArr[i]);
    }

    return ans;
}

int main()
{

    vector<int> A{1, 3, 1, 4, 2, 3, 5, 4};

    cout << solution(5, A) << endl;

    return 0;
}