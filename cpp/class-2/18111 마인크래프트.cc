#include <iostream>
#include <deque>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, b;
  cin >> n >> m >> b;

  int arr[257] = {0, };
  for(int i=0; i<n*m; i++) {
    int t;
    cin >> t;
    arr[t]++;
  }

  int front = 0, back = 256, c_time = 0;
  while(front != back) {
    if (arr[front] == 0) {
      front++;
      continue;
    }

    if (arr[back] == 0) {
      back--;
      continue;
    }

    if (arr[front] > b || arr[front] > arr[back] * 2) {
      b += arr[back];
      arr[back-1] += arr[back];
      c_time += arr[back--] * 2;
    } else {
      b -= arr[front];
      arr[front+1] += arr[front];
      c_time += arr[front++];
    }
  }
  cout << c_time << " " << front;
}