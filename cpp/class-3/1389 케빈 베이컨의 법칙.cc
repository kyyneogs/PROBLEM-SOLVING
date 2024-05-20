#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  int arr[n + 1][m + 1];
  int result[n + 1];
  memset(arr, 0, sizeof(arr));
  memset(result, 0, sizeof(result));

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    arr[x][y] = 1;
    arr[y][x] = 1;
  }

  int visited[n + 1];
  for (int i = 1; i <= n; i++) {
    queue<pair<int, int>> que;
    memset(visited, 0, sizeof(visited));

    int sumi = 0;
    visited[i] = 1;
    que.push({i, 0});

    while(!que.empty()) {
      int f = que.front().first;
      int d = que.front().second;
      sumi += d;
      que.pop();

      for(int j=1; j<=n; j++) {
        if (!arr[f][j] || visited[j]) continue;
        visited[j] = 1;
        que.push({j, d+1});
      }
    }
    result[i] = sumi;
  }
  int mini = 987654321;
  int ans;
  for(int i=1; i<=n; i++) 
    if (mini > result[i]) {
      ans = i;
      mini = result[i];
    }
  cout << ans;
}