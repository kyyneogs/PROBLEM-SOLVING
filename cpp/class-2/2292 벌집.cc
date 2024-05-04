#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  N -= 2;

  if (N < 0) {
    cout << 1;
    return 0;
  }

  N /= 6;
  int ans = 2, req = 0, rat = 2;
  while(req < N){
    req += rat;
    ans++;
    rat++;
  }
  cout << ans;
}