#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; ++test_case)
  {
    int ans = 0;
    priority_queue<int> q;

    int N;
    cin >> N;
    vector<int> V(N + 2);
    V[0] = -1;
    for (int i = 1; i <= N; ++i)
    {
      cin >> V[i];
    }
    V[N + 1] = -1;
    q.push(-1);

    for (int i = 1; i <= N; ++i)
    {
      if (q.top() < V[i] && V[i] > V[i + 1])
      {
        ++ans;
      }
      q.push(V[i]);
    }

    cout << "Case #" << test_case << ": " << ans << endl;
  }
  return 0;
}