#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  int arr[50001] = {};

  arr[0] = 1;
  for (int i = 1; i * i <= N; ++i) arr[i * i] = 1;

  if (arr[N] == 1) {
    cout << arr[N];
    return 0;
  }

  for (int i = 1; i <= N; ++i) {
    if (arr[i] == 1) continue;
    int j = 1;
    int remain = i - 1;
    int mini = 9999;
    while (remain > 0) {
      mini = arr[remain] + 1 < mini ? arr[remain] + 1 : mini;
      remain = i - j * j;
      j++;
    }
    arr[i] = mini;
  }
  cout << arr[N];
  return 0;
}