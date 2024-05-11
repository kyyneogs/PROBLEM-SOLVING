#include <algorithm>
#include <iostream>

using namespace std;

int bit_sec(int key, const int* arr, int size) {
  int begin = 0, end = size - 1;
  while (begin <= end) {
    int mid = (begin + end) / 2;
    if (key == arr[mid])
      return 1;
    else if (key > arr[mid])
      begin = mid + 1;
    else if (key < arr[mid])
      end = mid - 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  int* arr = new int[N];

  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    arr[i] = t;
  }
  sort(arr, arr + N);

  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    int t;
    cin >> t;
    cout << bit_sec(t, arr, N) << "\n";
  }
}