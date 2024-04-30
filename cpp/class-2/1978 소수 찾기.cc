#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int N, sumi = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int t, k = 0;
    cin >> t;
    if (t == 1) sumi--;
    for (int i = 2; i <= sqrt(t); i++) {
      if (t % i == 0) {
        k++;
        break;
      }
    }
    if (k == 0) sumi++;
  }
  cout << sumi;
}