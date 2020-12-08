#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A)
{

    // int INT_MIN = -1111111111;

    unordered_map<int, int> m;
    for (size_t i = 0; i < A.size(); ++i)
    {
        if (m.find(A[i]) == m.end())
        {
            m[A[i]] = 1;
        }
        else
        {
            m[A[i]] += 1;
        }
    }

    int leader = INT_MIN;

    unordered_map<int, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        if (itr->second > A.size() / 2)
        {
            leader = itr->first;
        }
    }

    if (leader == INT_MIN)
        return 0;

    int ans = 0;
    unordered_map<int, int> m1;
    for (size_t i = 0; i < A.size() - 1; ++i)
    {

        // add i's el
        if (m1.find(A[i]) == m1.end())
        {
            m1[A[i]] = 1;
        }
        else
        {
            m1[A[i]] += 1;
        }

        // remove i's el
        m[A[i]] -= 1;
        if (m[A[i]] == 0)
        {
            m.erase(A[i]);
        }

        if ((m1[leader] > (i + 1) / 2) && (m[leader] > (A.size() - (i + 1)) / 2))
        {
            ans += 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> A{4, 3, 4, 4, 4, 2};

    cout << solution(A) << endl;

    return 0;
}