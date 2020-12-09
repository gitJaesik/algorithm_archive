#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 0 <= N - 1
int solution(vector<int> &A) {
    vector<int> pres(A.size() + 1);

    pres[0] = 0;
    for (int i = 1; i < pres.size(); i++) {
        pres[i] = pres[i-1] + A[i-1];
    }

    int ans = 0;
    for (int i = 1; i < A.size() -1; i++) {
        for (int j = i + 2; j < A.size() - 1; j++) {
            int sum = pres[j + 1] - pres[i] - *min_element(A.begin() + i, A.begin() + j);
            ans = max(ans, sum);
        }
    }

    return ans;
}

int main() {

    vector<int> A {3, 2, 6, -1, 4, 5, -1, 2};

    cout << solution(A) << endl;

    return 0;
}
