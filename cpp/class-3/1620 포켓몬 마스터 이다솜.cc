#include <cctype>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  unordered_map<string, int> dict;
  dict.reserve(N);
  vector<string> vec;
  vec.reserve(N);

  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;

    dict[s] = i + 1;
    vec.push_back(s);
  }

  for (int i = 0; i < M; ++i) {
    string s;
    cin >> s;

    if ((int)s[0] < 48 || (int)s[0] > 57) {
      cout << dict[s] << "\n";
    } else {
      int _sz = s.size(), _n = (int)s[0] - 48;

      for (int i = 1; i < _sz; ++i) {
        _n *= 10;
        _n += (int)s[i] - 48;
      }
      cout << vec[_n-1] << "\n";
    }
  }
}