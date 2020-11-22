#include <iostream>
#include <vector>
#include <set>

using namespace std;
int solution(vector<int> &A)
{
    set<int> B;
    for (const auto& a: A) {
        B.insert(a);
    }
    return B.size();
}

int main() {
    vector<int> A {2, 1, 1, 2, 3, 1};
    cout << solution(A) << endl;
    return 0;
}

