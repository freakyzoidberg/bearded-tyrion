#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
  int count;
  cin >> count;
  vector<unsigned> mm;
  vector<unsigned> ff;
  unsigned mf_c;
  unsigned max_length = 0;
  
  while (count--) {
    string type;
    unsigned length;
    cin >> type >> length;
    if (type == "M-F" || type == "F-M") {
      max_length += length;
      mf_c++;
    } else if (type == "M-M") {
      mm.push_back(length);
    } else
      ff.push_back(length);
  } 
  

  sort(mm.begin(), mm.end(), greater<unsigned>());
  sort(ff.begin(), ff.end(), greater<unsigned>());

  unsigned add_max = min(mm.size(), ff.size());
  for (unsigned i = 0; i < add_max; i++) {
    max_length += mm[i] + ff[i];
  }
  cout << max_length << endl;

}
