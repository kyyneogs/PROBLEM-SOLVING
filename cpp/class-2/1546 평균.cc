#include <array>
#include <iostream>

using namespace std;

int main() {
  array<int, 1000> arr;
  int N, maxi = 0;
  float sumi = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (arr[i] > maxi)
      maxi = arr[i];
  }

  for (int i = 0; i < N; i++) 
    sumi += (float)arr[i]/(float)maxi*100;

  cout << sumi/(float)N;
}