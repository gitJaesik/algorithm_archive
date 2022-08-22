#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// compile command
// g++ -std=c++17 <file_name>

int main()
{

  vector<int> prices{2, 4, 1, 5, 6, 7, 10, 22, 12};

  sort(prices.begin(), prices.end());
  // sort(prices.begin(), prices.end(), [](const int &l, const int &r) -> bool
  //      { return l > r; });
  for (int i = 0; i < prices.size(); ++i)
  {
    cout << prices[i] << endl;
  }

  return 0;
}