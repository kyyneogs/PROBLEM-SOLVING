#include <algorithm>
#include <iostream>
#define uint unsigned

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int k, n;
  cin >> k >> n;

  uint arr[k];
  for (int i = 0; i < k; i++) cin >> arr[i];
  sort(arr, arr + k);

  uint front = 1, back = arr[k - 1];
  while (front <= back) {
    uint mid = (front + back) / 2;
    uint sumi = 0;
    for (int i = 0; i < k; i++) sumi += arr[i] / mid;

    if (sumi < n) {
      back = mid - 1;
    } else {
      front = mid + 1;
    }
  }
  cout << back;
}