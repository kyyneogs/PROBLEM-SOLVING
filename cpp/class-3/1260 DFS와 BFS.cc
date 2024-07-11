#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dfs(vector<int> &res, vector<vector<int>> &grp, vector<int> &vis, int now) {
  for (size_t i = 0; i < grp[now].size(); ++i) {
    int _vis = grp[now][i];
    if (vis[_vis]) continue;

    vis[_vis] = 1;
    res.push_back(_vis);
    dfs(res, grp, vis, _vis);
  }
}

void bfs(vector<int> &res, vector<vector<int>> &grp, vector<int> &vis, int st) {
  queue<int> que;
  que.push(st);

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (size_t i = 0; i < grp[now].size(); ++i) {
      int _now = grp[now][i];
      if (vis[_now]) continue;

      vis[_now] = 1;
      que.push(_now);
      res.push_back(_now);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M, V;
  cin >> N >> M >> V;

  vector<vector<int>> graph(N + 1);
  vector<int> visited_bfs(N + 1, 0);
  vector<int> visited_dfs(N + 1, 0);

  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= N; ++i) {
    sort(graph[i].begin(), graph[i].end());
  }

  vector<int> result_dfs;
  result_dfs.push_back(V);
  visited_dfs[V] = 1;
  dfs(result_dfs, graph, visited_dfs, V);
  for (int i : result_dfs) cout << i << " ";

  vector<int> result_bfs;
  result_bfs.push_back(V);
  visited_bfs[V] = 1;
  bfs(result_bfs, graph, visited_bfs, V);
  cout << "\n";
  for (int i : result_bfs) cout << i << " ";
}