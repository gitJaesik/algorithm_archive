#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }

    return gcd(b, a % b);
}

int solution(int N, int M) {

    int gcdRet = gcd(N, M);

    return N / gcdRet;
}

int main() {

    cout << solution(10, 4) << endl;

    return 0;
}