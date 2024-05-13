#include <cmath>
#include <iostream>
#include <memory>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);

  int M, N, arr[1000001] = {0, };
  arr[1] = 1;
  cin >> M >> N;

  for (int i = 2; i <= N; i++) {
    if (arr[i] > 0) continue;
    for (int j = i * 2; j <= N; j += i) {
      if (arr[j] > 0) continue;
      arr[j] = 1;
    }
  }

  for (int i = M; i <= N; i++)
    if (arr[i] == 0) cout << i << "\n";
}