#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, K;

  cin >> N >> K;

  int money[N];
  for (int i = 0; i < N; ++i) cin >> money[i];

  int mini = 0, result = 0;
  for (int i = N - 1; i >= 0 && K > 0; --i) {
    mini += K / money[i];
    K %= money[i];
  }
  cout << mini;
}