#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> getFibo(int n) {
    vector<int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);

    int i = 2;
    while(fibo[i - 1] + fibo[i - 2] <= n) {
        fibo.push_back(fibo[i - 1] + fibo[i - 2]);
        i += 1;
    }
    return fibo;
}

int solution(vector<int>& A) {

    int N = A.size();
    vector<int> fibo = getFibo(N + 1);

    queue<pair<int, int>> q;
    vector<bool> visited(N, false);

    int curPos = -1;
    for (int i = 1; i < fibo.size(); ++i) {
        int nextPos = curPos + fibo[i];
        if (nextPos == N) return 1;
        if (nextPos < N && A[nextPos] == 1 && visited[nextPos] != true) {
            q.push(make_pair(nextPos, 1));
            visited[nextPos] = true;
        }
    }

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < fibo.size(); ++i) {
            int nextPos = p.first + fibo[i];
            if (nextPos == N) return p.second + 1;
            if (nextPos < N && A[nextPos] == 1 && visited[nextPos] != true) {
                q.push(make_pair(nextPos, p.second + 1));
                visited[nextPos] = true;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> A{0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0};
    cout << solution(A) << endl;
    return 0;
}