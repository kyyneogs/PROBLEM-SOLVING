#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// 주의 : BFS 는 방문 전 visited 처리를 진행해야 중복 방문을 피할 수 있음.

struct coordi {
  int x;
  int y;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<string> arr;
  int N;
  cin >> N;
  arr.reserve(N);

  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    arr.emplace_back(s);
  }
  int visited[N][N];
  memset(visited, 0, sizeof(visited));

  int normal = 0, abnormal = 0;
  queue<coordi> que;

  int dx[] = {0, 0, -1, 1};
  int dy[] = {1, -1, 0, 0};
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      if (visited[x][y]) continue;
      que.push({x, y});
      char color = arr[x][y];
      ++normal;
      while (!que.empty()) {
        coordi now = que.front();
        que.pop();

        for (int i = 0; i < 4; ++i) {
          int nx = now.x + dx[i];
          int ny = now.y + dy[i];

          if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
          if (visited[nx][ny]) continue;
          if (color != arr[nx][ny]) continue;

          visited[nx][ny] = 1;
          que.push({nx, ny});
        }
      }
    }
  }

  memset(visited, 0, sizeof(visited));
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      if (visited[x][y]) continue;
      que.push({x, y});
      char color = arr[x][y];
      ++abnormal;
      while (!que.empty()) {
        coordi now = que.front();
        visited[now.x][now.y] = 1;
        que.pop();

        for (int i = 0; i < 4; ++i) {
          int nx = now.x + dx[i];
          int ny = now.y + dy[i];

          if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
          if (visited[nx][ny]) continue;
          if (arr[nx][ny] == color || arr[nx][ny] + color == 153) {
            visited[nx][ny] = 1;
            que.push({nx, ny});
          }
        }
      }
    }
  }
  cout << normal << " " << abnormal;
}