#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cc {
  int y;
  int x;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> board(N, vector<int>(M));
  vector<vector<int>> dist(N, vector<int>(M, -1));

  cc target = {};

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int t;
      cin >> t;
      board[i][j] = t;
      if (t == 2) {
        target = {i, j};
      } else if (t == 0) {
        dist[i][j] = 0;
      }
    }
  }

  queue<cc> que;
  que.push(target);
  dist[target.y][target.x] = 0;

  int dx[] = {0, 0, -1, 1};
  int dy[] = {1, -1, 0, 0};
  while (!que.empty()) {
    cc now = que.front();
    que.pop();

    for (int i = 0; i < 4; ++i) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if (dist[ny][nx] >= 0) continue;
      dist[ny][nx] = dist[now.y][now.x] + 1;
      que.push({ny, nx});
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << dist[i][j] << " ";
    }
    cout << "\n";
  }
}