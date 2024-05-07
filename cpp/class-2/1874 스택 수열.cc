#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  stack<int> st;
  vector<char> ans;
  int n;
  cin >> n;

  int tmini = 1;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    while (tmini <= k) {
      st.emplace(tmini++);
      ans.emplace_back('+');
    }

    if (st.empty() || st.top() > k) {
      cout << "NO";
      return 0;
    }

    ans.emplace_back('-');
    st.pop();
  }

  for (const char& s : ans) cout << s << "\n";
}