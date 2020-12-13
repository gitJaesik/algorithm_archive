#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {


    vector<int> absA(A.begin(), A.end());
    for (int i = 0; i < absA.size(); ++i) {
        absA[i] = abs(absA[i]);
    }

    set<int> setA(absA.begin(), absA.end());

    return setA.size();
}


int main() {

    vector<int> A{-5, -3, -1, 0, 3, 6};
    cout << solution(A) << endl;

    return 0;
}
/*
  A[0] = -5
  A[1] = -3
  A[2] = -1
  A[3] =  0
  A[4] =  3
  A[5] =  6
*/