#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int test_case = 0; test_case < T; ++test_case)
  {
    int N, M;
    cin >> N >> M;

    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
      int ci;
      cin >> ci;
      sum += ci;
    }

    cout << "Case #" << test_case + 1 << ": " << sum % M << endl;
  }
  return 0;
}