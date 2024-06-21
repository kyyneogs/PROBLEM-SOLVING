  #include <cstring>
  #include <iostream>
  #include <queue>
  #include <string>

  using namespace std;

  struct cordi {
    int x;
    int y;
  };

  int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    string board[N];
    for (int i = 0; i < N; ++i) cin >> board[i];

    int visited[N][M];
    memset(visited, 0, sizeof(visited));
    queue<cordi> que;

    visited[0][0] = 1;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    que.push({0, 0});
    while (!que.empty()) {
      cordi t = que.front();
      que.pop();
      if (t.x == N - 1 && t.y == M - 1) break;

      for (int i = 0; i < 4; ++i) {
        int nx = t.x + dx[i];
        int ny = t.y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny] == '0') continue;
        if (visited[nx][ny] > 0) continue;
        visited[nx][ny] = visited[t.x][t.y] + 1;
        que.push({nx, ny});
      }
    }

    cout << visited[N - 1][M - 1];
  }