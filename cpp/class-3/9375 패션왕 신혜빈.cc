#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    map<string, int> _map;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
      string s1, s2;
      cin >> s1 >> s2;

      if (_map.find(s2) == _map.end())
        _map.insert({s2, 1});
      else
        _map[s2] = _map[s2] + 1;
    }

    int ssize = _map.size();
    int arr[ssize];
    int idx = 0;
    for (auto &it : _map) arr[idx++] = it.second + 1;

    int sumi = 1;
    for (int i = 0; i < ssize; ++i) sumi *= arr[i];
    cout << sumi - 1 << "\n";
  }
}