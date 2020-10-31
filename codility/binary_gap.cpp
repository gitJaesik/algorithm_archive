#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int get_binary_gap(string str) {

    int ans = 0;
    int start = 0;
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == '1') {
            ans = max(ans, i - start - 1);
            start = i;
        }
    }

    return ans;
}

int solution(int N) {

    string str;
    int num = N;

    while (num != 1) {
        str.append(to_string(num % 2));
        num = num / 2;
    }

    str.append("1");
    reverse(str.begin(), str.end());

    return get_binary_gap(str);
}

int main() {

    cout << solution(9) << endl;
    // 2
    cout << solution(529) << endl;
    // 4
    cout << solution(20) << endl;
    // 1
    cout << solution(15) << endl;
    // 0
    cout << solution(32) << endl;
    // 0
    cout << solution(1041) << endl;
    // 5
    cout << solution(32) << endl;
    // 0

    return 0;
}