#include <iostream>
#include <queue>
#include <string>

using namespace std;

int _num(string s) {
  if (s == "push") return 1;
  if (s == "pop") return 2;
  if (s == "size") return 3;
  if (s == "empty") return 4;
  if (s == "front") return 5;
  if (s == "back") return 6;
  return 0;
}

int main() {
  int T;
  cin >> T;
  queue<int> que;
  while (T--) {
    string s;
    cin >> s;
    switch (_num(s)) {
      case 1:
        int n;
        cin >> n;
        que.push(n);
        break;
      case 2:
        if (!que.empty()) {
          cout << que.front() << "\n";
          que.pop();
        } else
          cout << "-1\n";
        break;
      case 3:
        cout << que.size() << "\n";
        break;
      case 4:
        cout << que.empty() << "\n";
        break;
      case 5:
        if (!que.empty())
          cout << que.front() << "\n";
        else
          cout << "-1\n";
        break;
      case 6:
        if (!que.empty())
          cout << que.back() << "\n";
        else
          cout << "-1\n";
        break;
    }
  }
}