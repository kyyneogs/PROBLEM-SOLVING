#include <cmath>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  s += '+';
  deque<int> _tnum;
  deque<int> num;
  bool flag = false;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] >= 48) {
      _tnum.push_back((int)s[i] - 48);
    } else {
      int sumi = 0;
      while (!_tnum.empty()) {
        sumi += pow(10, _tnum.size() - 1) * _tnum.front();
        _tnum.pop_front();
      }
      if (flag) {
        int _sumi = num.back();
        num.pop_back();
        num.push_back(_sumi + sumi);
        flag = false;
      } else {
        num.push_back(sumi);
      }
      if (s[i] == '+') flag = true;
    }
  }

  int result = num.front();
  num.pop_front();
  while (!num.empty()) {
    result -= num.back();
    num.pop_back();
  }

  cout << result;
}