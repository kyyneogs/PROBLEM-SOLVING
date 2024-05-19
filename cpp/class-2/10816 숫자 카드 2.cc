#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  unordered_map<int, int> dict;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    if (dict.find(t) == dict.end())
      dict.insert(make_pair(t, 1));
    else
      (dict[t] += 1);
  }

  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int t;
    cin >> t;
    if (dict.find(t) == dict.end())
      cout << "0 ";
    else
      cout << dict[t] << " ";
  }
}