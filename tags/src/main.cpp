#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


typedef pair<string, unsigned> tag_count;

struct CountCmp {
  bool operator()(const tag_count &lhs, const tag_count &rhs) {
    return lhs.second > rhs.second;
  }
};

int main(int argc, char** argv)
{
  int count;
  string word;
  map<string, unsigned> cloud;

  cin >> count;
    while(count--) {
    cin >> word;
    cloud[word]++;
  }
  vector<tag_count> tags(cloud.begin(), cloud.end());
  partial_sort(tags.begin(), tags.begin() + 5, tags.end(), CountCmp());
  vector<tag_count>::const_iterator it = tags.begin();
  for (; it != tags.begin() + 5; it++)
    cout << it->first << " " << it->second << endl;
}
