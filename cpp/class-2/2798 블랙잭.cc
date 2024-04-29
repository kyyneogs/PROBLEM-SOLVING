#include <array>
#include <iostream>

using namespace std;

int main() {
  int N, M;
  array<int, 100> arr;

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> arr[i];

  int mini = 0;
  for (int i = 0; i < N - 2; i++)
    for (int j = i + 1; j < N - 1; j++)
      for (int k = j + 1; k < N; k++) {
        int sumi = arr[i] + arr[j] + arr[k];
        if (sumi <= M && sumi > mini){
          mini = sumi;
        }
      }
  cout << mini;
}