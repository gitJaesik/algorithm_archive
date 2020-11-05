#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


int solution(vector<int> &A) {

    unordered_map<int, int> u;

    for (const auto& num: A) {
        if (u.find(num) == u.end()) {
            u[num] = 1;
        } else {
            u[num] = u[num] + 1;
        }
    }

    int ans = -1;

    for (const auto& p: u) {
        if (p.second % 2 == 1) {
            ans = p.first;
            break;
        }
    }

    return ans;

}

int main() {

    vector<int> A{9, 3, 9, 3, 9, 7, 9};
    cout << solution(A) << endl;

    return 0;
}