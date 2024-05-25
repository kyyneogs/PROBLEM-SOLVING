#include <iostream>
#include <map>
#include <string>
#pragma GCC optimize("Ofast")

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  map<string, string> dict;
  for (int i = 0; i < n; i++) {
    string key, value;
    cin >> key >> value;
    dict.insert({key, value});
  }

  for (int i = 0; i < m; i++) {
    string key;
    cin >> key;
    
    cout << dict.find(key)->second << "\n";
  }
}