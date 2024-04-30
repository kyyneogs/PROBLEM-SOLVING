#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

struct cordi {
  int x;
  int y;
};

bool cmp(const cordi &a, const cordi &b) {
  if (a.x == b.x) {
    return a.y < b.y;
  } else
    return a.x < b.x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  array<cordi, 1000000> arr;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i].x >> arr[i].y;

  sort(arr.begin(), arr.begin() + N, cmp);

  for (int i = 0; i < N; i++) cout << arr[i].x << " " << arr[i].y << "\n";
}