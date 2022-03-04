#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

// 쌍 pair
// Z : 1 ~ 6000

// 보이면 오버플로우 확인
// 여기서는 소수 구하는 끝
// long long으로 소수를 구해야함 j*j 가 overflow가 발생 할 수 있음

// int max많큼 존재하는 경우이기 때문에, 소수를 그 때 그 때 구하는게 낫지 않을까?
// 라고 생각하면 O(n) = 20억이니까 1초가 걸림
//  A, B : 1 ~ 2,147,483,647

// 4 GB
// 4 * 1,000,000,000
// int fPrime[2147483647];
int fPrime[2147483647];

vector<int> getDivisors(int P) {
    set<int> setDivisors;

    int x = P;
    // get P's divisors
    while (true) {
        if (fPrime[x] != 0) {
            setDivisors.insert(fPrime[x]);
            x /= fPrime[x];
        }
    }
    setDivisors.insert(x);

    vector<int> divisors(setDivisors.begin(), setDivisors.end());

    sort(divisors.begin(), divisors.end());

    return divisors;
}

int solution(vector<int>& A, vector<int> &B) {
    memset(fPrime, 0, sizeof(fPrime));
    for (long long i = 2; i * i<= 2147483647; ++i) {
        if (fPrime[i] == 0) {
            for (long long j = i * i; j <= 2147483647; j += i) {
                if (fPrime[j] == 0) {
                    fPrime[j] = i;
                }
            }
        }
    }

    int Z = A.size();
    int ans = 0;
    for (int i = 0; i < Z; ++i) {
        if (getDivisors(A[i]) == getDivisors(B[i])) {
            ans += 1;
        }
    }

    return ans;
}

int main() {
    vector<int> A{15, 10, 3};
    vector<int> B{75, 30, 5};

    cout << solution(A, B) << endl;

    return 0;
}
