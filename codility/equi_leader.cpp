#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int getLeader(vector<int> &A, size_t begin, size_t end) {
    unordered_map<int, int> m;
    for (size_t i = begin; i <= end; ++i) {
        if (m.find(A[i]) == m.end()) {
            m[A[i]] = 1;
        } else {
            m[A[i]] += 1;
        }
    }

    int leader = INT_MIN;

    unordered_map<int, int>:: iterator itr; 
    for (itr = m.begin(); itr != m.end(); itr++) 
    { 
        if (itr->second > (end - begin + 1) / 2) {
            return leader = itr->first;
        }
     } 

    return leader;
}

int solution(vector<int> &A) {

    int leader = getLeader(A, 0, A.size() -1);
    if (leader == INT_MIN) return 0;

    int ans = 0;
    for (size_t i = 0; i < A.size() -1; ++i) {
        int m1 = getLeader(A, 0, i);
        int m2 = getLeader(A, i+1, A.size() -1);
        if (leader == m1 && leader == m2) ans +=1;
    }

    return ans;
}


int main() {

    vector<int> A{4, 3, 4, 4, 4, 2};

    cout << solution(A) << endl;

    return 0;
}