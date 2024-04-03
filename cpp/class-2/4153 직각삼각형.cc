#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int a[3];
  while (1) {
    cin >> a[0] >> a[1] >> a[2];
    if (a[0] == 0 && a[1] == 0 && a[2] == 0)
      break;
    sort(a, a + 3, greater<>());
    if (pow(a[0], 2) == pow(a[1], 2) + pow(a[2], 2))
      cout << "right\n";
    else
      cout << "wrong\n";
  }
}