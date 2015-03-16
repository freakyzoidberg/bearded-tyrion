#include <vector>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

string getTrend(list<string> &hs)
{
  vector<string> order;
  unordered_map<string, int> counter;
  for (auto &h : hs) {
    counter[h]++;
    if (counter[h] == 1)
      order.push_back(h);
  }
  for (auto &h : order) {
    if (counter[h] >= 40)
      return h;
  }
  return "";
}


int main(int argc, char** argv)
{
  list<string> hashs;
  unsigned count;
  cin >> count;

  while (count--) {
    string hash;
    cin >> hash;
    hashs.push_back(hash);
    if (hashs.size() >= 60) {
      string res = getTrend(hashs);
      if (!res.empty()) {
        cout << res << endl;
        return 0;
      }
      hashs.pop_front();
    }
  }
  cout << "Pas de trending topic" << endl;
  return 0;
}
