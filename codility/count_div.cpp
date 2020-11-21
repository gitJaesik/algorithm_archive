#include <iostream>

using namespace std;

int solution(int A, int B, int K)
{
    // write your code in C++14 (g++ 6.2.0)

    int extra = 0;

    if (A % K == 0) extra = 1;
    return (B / K - A / K) + extra;
}

int main() {

    cout << solution(6, 11, 2) << endl;

    return 0;
}