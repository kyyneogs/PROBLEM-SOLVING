#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  long long arr[101] = {1, 1, 1, 2, 2};
  for (int i = 5; i <= 100; ++i) arr[i] = arr[i - 1] + arr[i - 5];
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    cout << arr[N - 1] << "\n";
  }
}