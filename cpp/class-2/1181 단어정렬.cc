#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(const string &a, const string &b) {
  if (a.length() == b.length())
    return a < b;
  else
    return a.length() < b.length();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<string> arr;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    arr.emplace_back(s);
  }
  sort(arr.begin(), arr.end(), cmp);
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  for (const string &i : arr) cout << i << "\n";
}