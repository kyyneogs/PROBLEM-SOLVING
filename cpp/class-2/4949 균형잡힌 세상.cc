#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while (1) {
    stack<char> stack_;
    string s;
    getline(cin, s);
    if (s[0] == '.' && s.size() == 1) break;
    int it_cnt = 0;
    for (const char &it : s) {
      if (it == '(')
        stack_.push(it);
      else if (it == '[')
        stack_.push(it);
      else if (it == ')') {
        if (stack_.empty() || stack_.top() != '(')
          break;
        else
          stack_.pop();
      } else if (it == ']') {
        if (stack_.empty() || stack_.top() != '[')
          break;
        else
          stack_.pop();
      }
      it_cnt++;
    }
    if (it_cnt == s.size() && stack_.empty()) cout << "yes\n";
    else cout << "no\n";
  }
}