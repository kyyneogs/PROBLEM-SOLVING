#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  int visited[101] = {};
  vector<vector<int>> vec(N + 1);

  int T;
  cin >> T;
  while (T--) {
    int a1, a2;
    cin >> a1 >> a2;

    vec[a1].emplace_back(a2);
    vec[a2].emplace_back(a1);
  }

  queue<int> que;
  visited[1] = 1;
  que.emplace(1);

  int result = 0;

  while (!que.empty()) {
    int t = que.front();
    que.pop();

    for (int i = 0; i < vec[t].size(); ++i) {
      int l = vec[t][i];
      if (visited[l]) continue;
      visited[l] = 1;
      que.emplace(l);
      result++;
    }
  }

  cout << result;
}