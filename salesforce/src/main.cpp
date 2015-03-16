#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

static const regex phone_reg("\\+[0-9]{1,3}-[0-9]{9,11}");
                          
void split(const string &s, char delim, vector<string> &elems) {
  stringstream ss(s);
  string item;

  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
}

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  split(s, delim, elems);
  return elems;
}

class Person {
public:
  Person(vector<string> &v) {
    last_name = v[0];
    first_name = v[1];
    company = v[2];
    phone = v[3];
    country = v[4];
  }
  ~Person() {}
  bool operator<( const Person& other) const
  {
    if ( last_name == other.last_name ) {
      if (first_name == other.first_name) {
        return company < other.company;
      }
      return first_name < other.first_name;  
    }
    return last_name < other.last_name;
  }
  bool phoneIsValid() const {
    return regex_match(phone, phone_reg);
        
  }

  string last_name;
  string first_name;
  string company;
  string phone;
  string country;
};



int main(int argc, char** argv)
{
  int count;
  vector<string> countries;
  map<Person, unsigned> dedup_store;
  string tmp;

  cin >> count;
  cin >> tmp;
  countries = split(tmp, ';');
  std::sort(countries.begin(), countries.end());

  while (count--) {
    cin >> tmp;
    vector<string> v = split(tmp, ';');
    dedup_store[Person(v)]++;
  }

  unsigned dup = 0;
  unsigned error = 0;
  unsigned outside = 0;
  for (auto &p : dedup_store) {
    dup += p.second - 1;
    error += (p.first.phoneIsValid()?0:1);
    vector<string>::const_iterator zone_it;
    zone_it = lower_bound(countries.begin(), countries.end(), p.first.country);
    if (zone_it == countries.end() || *zone_it != p.first.country)
      outside++;
  }
  
  cout << dup << " " << error << " " << outside << endl;
}
