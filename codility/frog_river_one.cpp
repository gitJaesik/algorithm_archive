#include <iostream>
#include <vector>

using namespace std;

int checkIsPossible(vector<int> &arr)
{

    int sum = 0;
    for (const auto &ar : arr)
    {
        sum += ar;
    }
    return sum;
}

int solution(int X, vector<int> &A)
{

    vector<int> arr(X + 1, -1);
    arr[0] = 0;

    // cout << arr.size() << endl;

    for (size_t i = 0; i < A.size(); i++)
    {
        arr[A[i]] = 0;
        if (checkIsPossible(arr) == 0)
            return i;
    }

    return -1;
}

int main()
{

    vector<int> A{1, 3, 1, 4, 2, 3, 5, 4};

    cout << solution(5, A) << endl;

    return 0;
}