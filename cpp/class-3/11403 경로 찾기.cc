#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;

  int arr[N][N];
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> arr[i][j];

  for (int x = 0; x < N; ++x) {
    queue<int> que;
    int visited[N];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; ++i)
      if (arr[x][i] != 0) que.push(i);

    while (!que.empty()) {
      int t = que.front();
      que.pop();

      if (visited[t]) continue;
      visited[t] = 1;

      for (int i = 0; i < N; ++i) {
        if (arr[t][i]) que.push(i);
      }
    }

    for (int i = 0; i < N; i++) cout << visited[i] << " ";
    cout << "\n";
  }
}