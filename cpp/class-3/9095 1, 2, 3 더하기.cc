#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  int arr[10];

  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 4;

  for (int i = 3; i < 10; ++i) {
    arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
  }

  while (t--) {
    int n;
    cin >> n;
    cout << arr[n - 1] << "\n";
  }
}