#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {

    int ans = 0;

    int sum = 0;

    for (const auto & a: A) {

        if (a == 0) {
            sum += 1;
        } else {
            ans += sum;
        }

        if (ans > 1000000000) return -1;
    }

    return ans;
}


int main() {

    vector<int> A{0, 1, 0, 1, 1};
    cout << solution(A) << endl;

    return 0;
}