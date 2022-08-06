#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

  int n, m;

  cin >> n >> m;

  vector<int> cards;

  for (int i = 0; i < n; i++)
  {
    int card;
    cin >> card;
    cards.push_back(card);
  }

  // for (int i = 0; i < cards.size(); ++i)
  // {
  //   cout << cards[i] << endl;
  // }

  int ans = 0;
  for (int i = 0; i < cards.size() - 2; ++i)
  {
    for (int j = i + 1; j < cards.size() - 1; ++j)
    {
      for (int k = j + 1; k < cards.size(); ++k)
      {
        int cadicate = cards[i] + cards[j] + cards[k];
        if (cadicate > m)
        {
          continue;
        }
        // 현재 가장 가까운 값
        int current_ans = m - ans;
        // 방금 구한 경우의 수에서 가장 가까운 값
        int cadicate_ans = m - cadicate;
        if (abs(current_ans) > abs(cadicate_ans))
        {
          ans = cadicate;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}