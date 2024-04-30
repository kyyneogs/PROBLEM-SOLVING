#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int N;
  cin >> N;

  for (int i = 1; i < N; i++) {
    int t = i;
    int tmp = i;
    while (t > 0) {
      tmp += t % 10;
      t /= 10;
    }
    if (tmp == N) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}