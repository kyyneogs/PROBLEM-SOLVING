#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  std::vector<unsigned int> arr(N);
  for (int i = 0; i < N; ++i) cin >> arr[i];

  std::vector<unsigned long long> dp(N + 3);

  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 0;
  dp[3] = arr[0];

  for (int i = 4; i < N + 3; ++i) {
    int t1 = dp[i - 3] + arr[i - 4] + arr[i - 3];
    int t2 = dp[i - 2] + arr[i - 3];
    dp[i] = (t1 > t2) ? t1 : t2;
  }
  std::cout << dp[N + 2];
}