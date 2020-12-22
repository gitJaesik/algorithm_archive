#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// upstream 0 => to negative
// downstream 1 => to positive

// N : 1 ~ 100,000
// A[i]: 0 ~ 1000,000,000
// B[i] : 0, 1
// 1 : {
// 0 : }

// algorithm
// 


int solution(vector<int> &A, vector<int> &B) {
    // N - number of eaten
    int N = A.size();
    int ans = N;

    stack<int> s;
    for (int i = 0; i < N; ++i) {
        if (B[i] == 1) {
            s.push(A[i]);
        } else {
            while (!s.empty()) {
                if (s.top() < A[i]) {
                    ans -= 1;
                    s.pop();
                }
                else {
                    ans -= 1;
                    break;
                }
            }
        }
    }

    return ans;
}

int main() {
    vector<int> A { 4, 3, 2, 1, 5};
    vector<int> B { 0, 1, 0, 0, 0};

    cout << solution(A, B) << endl;
    
    return 0;
}


// 저번의 도로 지나가는 거 확인해야겠다.