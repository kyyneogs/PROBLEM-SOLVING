#include <cmath>
#include <iostream>

using namespace std;

int _round(double x) { return (int)floor(x + 0.5); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, arr[31] = {0, };
  cin >> N;

  if (N == 0) {
    cout << 0;
    return 0;
  }

  int _mean = _round((double)N * 0.15);
  int t_cnt = N - 2 * _mean;

  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    arr[t]++;
  }

  for (int i = 1, t_mean = _mean; t_mean > 0; i++) {
    while (t_mean > 0 && arr[i] > 0) {
      arr[i]--;
      t_mean--;
    }
  }

  for (int i = 30, t_mean = _mean; t_mean > 0; i--) {
    while (t_mean > 0 && arr[i] > 0) {
      arr[i]--;
      t_mean--;
    }
  }

  int sumi = 0;
  for (int i = 1; i <= 30; i++) sumi += i * arr[i];
  sumi = _round((double)sumi / t_cnt);
  cout << sumi;
  return 0;
}