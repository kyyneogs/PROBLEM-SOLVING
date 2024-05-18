#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, arr[10001] = {0, };
  int mini = 10001, maxi = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    arr[t]++;
    mini = (mini < t) ? mini : t;
    maxi = (maxi > t) ? maxi : t;
  }

  for (int i = mini; i <= maxi; i++) {
    if (arr[i] == 0) continue;
    for (int j = 0; j < arr[i]; j++) cout << i << "\n";
  }
}