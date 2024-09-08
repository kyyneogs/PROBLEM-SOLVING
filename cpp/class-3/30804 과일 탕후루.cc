#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  vector<int> arr;
  set<int> bag;
  int cnt[10] = {};

  cin >> N;
  arr.reserve(N);

  for (int i = 0; i < N; ++i) cin >> arr[i];

  int front = 0, back = 0, max_size = 0, now_size = 0;
  bag.insert(arr[0]);
  while (front < N && back < N) {
    if (arr[front] == arr[back]) {
      ++now_size;
      ++cnt[arr[back]];
      ++back;
    } else {
      bag.insert(arr[back]);
      if (bag.size() <= 2) {
        ++now_size;
        ++cnt[arr[back]];
        ++back;
      } else {
        while (bag.size() > 2 && front < N) {
          --now_size;
          --cnt[arr[front]];
          if (cnt[arr[front]] == 0) {
            bag.erase(arr[front]);
          }
          ++front;
        }
      }
    }
    max_size = (now_size > max_size) ? now_size : max_size;
  }
  std::cout << max_size;
}