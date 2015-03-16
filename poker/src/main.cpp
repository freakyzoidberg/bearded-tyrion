#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  long long money;
  int games;
  cin >> money;
  cin >> games;

  while (games--) {
    long long bet, win;
    cin >> bet >> win;
    money+= (win - bet);
  }
  cout << money << endl;
}
