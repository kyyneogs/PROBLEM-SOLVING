#include <iostream>

using namespace std;

long long factorial(long long x) {
  if (x == 1)
    return 1;
  else
    return x * factorial(x - 1);
}

int main() {
  int t;
  cin >> t;

  long long fac = factorial(t);
  int ans = 0;
  while (fac >= 10) {
    if (fac % 10 != 0) break;
    ans ++;
    fac /= 10;
  }
  cout << ans;
}