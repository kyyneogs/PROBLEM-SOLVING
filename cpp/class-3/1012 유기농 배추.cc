#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cc {
  int n;
  int m;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int T;
  cin >> T;

  int dx[] = {0, 0, -1, 1};
  int dy[] = {1, -1, 0, 0};
  while (T--) {
    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    vector<cc> rdy;
    for (int i = 0; i < K; ++i) {
      int a, b;
      cin >> a >> b;
      rdy.push_back({b, a});
      board[b][a] = 1;
    }

    int cnt = 0;
    queue<cc> que;
    for (int i = 0; i < (int)rdy.size(); ++i) {
      cc _now = rdy[i];
      if (visited[_now.n][_now.m]) continue;

      visited[_now.n][_now.m] = 1;
      que.push(_now);
      ++cnt;
      while (!que.empty()) {
        cc now = que.front();
        que.pop();

        for (int j = 0; j < 4; ++j) {
          int nx = now.m + dx[j];
          int ny = now.n + dy[j];

          if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
          if (!board[ny][nx]) continue;
          if (visited[ny][nx]) continue;

          visited[ny][nx] = 1;
          que.push({ny, nx});
        }
      }
    }
    cout << cnt << "\n";
  }
}