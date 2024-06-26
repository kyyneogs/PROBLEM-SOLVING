#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;

    int oc = 0;
    for (const char& i : s) {
      if (i == '(')
        oc++;
      else
        oc--;

      if (oc < 0) break;
    }
    if (oc < 0 or oc > 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}