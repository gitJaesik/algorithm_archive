// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// length
// I
// N : 1 ~ 100,000
// K : 1 ~ 1,000,000,000
// A[i] : 1 ~ 1,000,000,000

// maximal rope greater or equal to K
// Idea : how to access to this problem
// 제일 작은 거 찾고, 그 양쪽 중 작은 거 골라서 합치기

void knotRope(vector<int> &A, vector<int> &cntMerge, int minElIdx, int mergeIdx)
{
    A[minElIdx] = A[minElIdx] + A[mergeIdx];
    A.erase(A.begin() + mergeIdx);
    cntMerge[minElIdx] = cntMerge[minElIdx] + cntMerge[mergeIdx];
    cntMerge.erase(cntMerge.begin() + mergeIdx);
}

int solution(int K, vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    vector<int> cntMerge(A.size(), 1);

    // merge all until smallest one is greater that or equal to K
    int ans = -1;
    while (true)
    {
        vector<int>::iterator it = min_element(A.begin(), A.end());
        if (*it >= K)
            break;

        // get current index
        int index = it - A.begin();

        if (it == A.begin())
        {
            knotRope(A, cntMerge, index, index + 1);
        }
        else if (it == A.end() - 1)
        {
            knotRope(A, cntMerge, index, index - 1);
        }
        else
        {
            if (A[index + 1] < A[index - 1])
            {
                knotRope(A, cntMerge, index, index + 1);
            }
            else
            {
                knotRope(A, cntMerge, index, index - 1);
            }
        }
    }
    for (const auto &el : cntMerge)
    {
        ans = max(ans, el);
    }
    return ans;
}

int main () {

    // vector<int> A {1, 2, 3, 4, 1, 1, 3};
    vector<int> A {1, 1, 1, 1, 1, 1, 1};
    cout << solution(4, A) << endl;

    return 0;
}