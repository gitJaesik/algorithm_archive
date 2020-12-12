#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// arrayF
vector<int> getPrime() {
    vector<int> arrayF(500000 * 2 + 1, 1);
    arrayF[0] = 0;

    for (int i = 2; i * i <= 500000 * 2; i++ ) {
        if (arrayF[i] == 1) {
            for (int j = i * i; j <= 500000 * 2; j += i) {
                if (arrayF[j] == 1) {
                    arrayF[j] = i;
                }
            }
        }
    }

    return arrayF;

}

// factorization
// 10
vector<int> getFactorization(int x, const vector<int>& arrayF) {

    if (x == 1) {
        return vector<int>{1};
    }
    set<int> setFac;

    int xx = x;
    int div = 0;
    int lastPush = 0;
    while (true) {
        div = arrayF[xx];
        setFac.insert(div);
        if (div == 1) break;
        xx = xx / div;
    }

    setFac.insert(xx);
    setFac.insert(x);

    vector<int> fac(setFac.begin(), setFac.end());

    return fac;
}

vector<int> solution(vector<int> &A) {

    vector<int> arrayF = getPrime();
    vector<int>ans;

    for (int i = 0; i < A.size(); i++) {
        int currentElAns = A.size();
        vector<int> fac = getFactorization(A[i], arrayF);

        for (int j = 0; j < fac.size(); j++) {
            vector<int>::iterator it = A.begin();
            while (true) {
                it = find(it, A.end(), fac[j]);
                if (it == A.end()) break;
                currentElAns--;
                it = it + 1;
            }
        }
        ans.push_back(currentElAns);
    }


    return ans;
}



int main() {
    // vector<bool> soe(500000 * 2 + 1, true);

    // soe[0] = false;
    // soe[1] = false;

    // for (int i = 2; i * i <= 500000 * 2; i++) {
    //     if (soe[i]) {
    //         for (int j = i * i; j <= 500000 * 2; j += i) {
    //             soe[j] = false;
    //         }
    //     }
    // }

    // vector<int> arrayF = getPrime();
    // for (int i = 1; i <= 40; i++) {
    //     vector<int> fac = getFactorization(i, arrayF);
    //     for (const auto& fa : fac) {
    //         cout << fa << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> A{3, 1, 2, 3, 6};
    vector<int> ans = solution(A);
    for (const auto& an : ans) {
        cout << an << endl;
    }

    return 0;
}
