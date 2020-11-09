#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {

    int total_size = A.size();

    unordered_map<int, int> u;
    for (const auto& num: A) {
        if (u.find(num) == u.end()) {
            u[num] = 1;
        } else {
            u[num] += 1;
        }
    }

    for (const auto& p: u) {
        if (p.second > (total_size / 2)) {

            for (int i = 0; i < A.size(); ++i) {
                if (A[i] == p.first) {
                    return i;
                }
            }
        }
    }

    return -1;
}

int main() {

    vector<int> A{3, 4, 3, 2, 3, -1, 3, 3};

    cout << solution(A) << endl;

    return 0;
}