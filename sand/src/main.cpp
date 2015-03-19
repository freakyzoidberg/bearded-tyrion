#include <vector>
#include <iostream>

using namespace std;

class Map {
public:
  Map(int h, int l) : _map(), _h(h), _l(l) {}
  void addRow(std::string &r) {
    for (auto &c : r) {
      _map.push_back(c == '.' ? -1 : -2);
    }
  }
  
  int calculateCost() {
    bool done = false;
    while (!done) {
      done = true;
      for (int i = 0; i < _map.size(); i++) {
        if (_map[i] == -2) {
          done = false;
          int cost = getCostAround(i);
          if (cost > 0)
            _map[i] = cost;
        }
      }
    }
    return *max_element(_map.begin(), _map.end());
  }

private:
  vector<int> _map;
  int _h;
  int _l;
  int getCostAround(int i) {
    int cost = 0;
    int x = i % _l;
    int y = i / _l;
    
    if (y >= 1) {
      int t = at(x, y - 1);
      if (t == -1)
        return 1;
      if (cost < t)
        cost = t + 1;
    }
    
    if (y < (_h - 1)) {
      int t = at(x, y + 1);
      if (t == -1)
        return 1;
      if (cost < t)
        cost = t + 1;
    }
    
    if (x < (_l - 1)) {
      int t = at(x + 1, y);
      if (t == -1)
        return 1;
      if (cost < t)
        cost = t + 1;
    }
    
    if (x >= 1) {
      int t = at(x - 1, y);
      if (t == -1)
        return 1;
      if (cost < t)
        cost = t + 1;
    }
    
    return cost;
  }
  int at(int x, int y) {
    return _map[y * _l + x];
  }
};


int main(int argc, char** argv)
{
  int h, l;
  cin >> h >> l;
  
  Map map(h, l);
  while (l--)
  {
    string row;
    cin >> row;
    map.addRow(row); 
  }
  cout << map.calculateCost() << endl;;
}

