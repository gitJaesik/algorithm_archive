#include <iostream>
#include <string>

using namespace std;

int solution(int X, int Y, int D) {

    int ans = 0;

    if (X == Y) return ans;

    ans = (Y - X) / D;

    if ((Y - X) % D == 0) {
        return ans;
    }

    return ans + 1;
}

int main() {

    cout << solution(10, 85, 30) << endl;

    return 0;
}