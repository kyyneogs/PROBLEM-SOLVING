#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct pos {
  int x;
  int y;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<string> board;
  board.reserve(n);

  int sx, sy;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < m; j++) {
      if (s[j] == 'I') {
        sx = i;
        sy = j;
      }
    }
    board.emplace_back(s);
  }

  bool visited[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) visited[i][j] = false;

  queue<pos> que;
  que.push({sx, sy});
  visited[sx][sy] = true;

  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  int person = 0;
  while (!que.empty()) {
    pos now = std::move(que.front());
    que.pop();

    for (int i = 0; i < 4; i++) {
      int nx = now.x + dx[i];
      int ny = now.y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == 'X' || visited[nx][ny]) continue;
      if (board[nx][ny] == 'P') ++person;
      visited[nx][ny] = true;
      que.push({nx, ny});
    }
  }
  if (person == 0) cout << "TT";
  else cout << person;
}
