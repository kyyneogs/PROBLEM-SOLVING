#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct cd {
  int x;
  int y;
  cd(int x, int y) : x(x), y(y) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  string board[N];
  int visited[N][N];
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < N; ++i) cin >> board[i];

  vector<int> result;
  int dx[] = {0, 0, -1, 1};
  int dy[] = {1, -1, 0, 0};
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      if (visited[x][y]) continue;
      if (board[x][y] == '0') continue;

      visited[x][y] = 1;
      queue<cd> que;
      que.emplace(x, y);

      int cnt = 1;
      while (!que.empty()) {
        cd _cd = que.front();
        que.pop();

        for (int i = 0; i < 4; ++i) {
          int nx = _cd.x + dx[i];
          int ny = _cd.y + dy[i];

          if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
          if (board[nx][ny] == '0') continue;
          if (visited[nx][ny]) continue;
          visited[nx][ny] = 1;
          que.emplace(nx, ny);
          cnt++;
        }
      }
      result.emplace_back(cnt);
    }
  }
  sort(result.begin(), result.end());
  cout << result.size() << "\n";
  for (int i = 0; i < result.size(); ++i) cout << result[i] << "\n";
}