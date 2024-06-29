#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct{
  int H;
  int N;
  int M;
} cc;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int M, N, H;
  cin >> M >> N >> H;

  int arr[H][N][M];
  vector<cc> stp;

  int cnt_blk = 0, cnt_tmt = 0;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < M; ++k) {
        int t;
        cin >> t;
        arr[i][j][k] = t;
        if (t == 1) {
          stp.push_back({i, j, k});
          ++cnt_tmt;
        } else if (t == -1) {
          ++cnt_blk;
        }
      }
    }
  }

  queue<cc> que;
  for (int i = 0; i < stp.size(); ++i) {
    que.push(stp[i]);
  }

  int maxi = 1;
  int dh[] = {0, 0, 0, 0, -1, 1};
  int dn[] = {1, -1, 0, 0, 0, 0};
  int dm[] = {0, 0, -1, 1, 0, 0};

  while (!que.empty()) {
    cc now = que.front();
    que.pop();
    int tmt = arr[now.H][now.N][now.M];

    for (int i = 0; i < 6; ++i) {
      int nH = now.H + dh[i];
      int nN = now.N + dn[i];
      int nM = now.M + dm[i];

      if (nH < 0 || nH >= H || nM < 0 || nM >= M || nN < 0 || nN >= N) continue;
      if (arr[nH][nN][nM] != 0) continue;

      arr[nH][nN][nM] = tmt + 1;
      maxi = maxi > tmt + 1 ? maxi : tmt + 1;
      que.push({nH, nN, nM});
      ++cnt_tmt;
    }
  }

  if (M * N * H != cnt_blk + cnt_tmt)
    cout << -1;
  else
    cout << maxi - 1;
}