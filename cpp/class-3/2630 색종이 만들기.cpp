#include <iostream>
#pragma GCC optimize("Ofast")

using namespace std;

struct ss {
  int w, b;
  ss() : w(0), b(0) {}
};

void dd(ss &ss, int _x, int _y, int **board, int len) {
  int wh[2] = {0, 0};
  bool flag = true;
  for (int i = 0; i < len && flag; i++) {
    for (int j = 0; j < len && flag; j++) {
      int x = _x + i;
      int y = _y + j;

      wh[board[x][y]]++;
      if (wh[0] > 0 && wh[1] > 0) flag = false;
    }
  }

  if (!flag) {
    for (int i = 0; i < 4; i++)
      dd(ss, _x + (len / 2) * (i / 2), _y + (len / 2) * (i % 2), board, len / 2);
  } else {
    if (wh[0] > 0) ss.w++;
    if (wh[1] > 0) ss.b++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ss wb;
  int n;
  cin >> n;
  int **arr = new int *[n];
  for (int i = 0; i < n; i++) arr[i] = new int[n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> arr[i][j];

  dd(wb, 0, 0, arr, n);
  cout << wb.w << " " << wb.b;
}