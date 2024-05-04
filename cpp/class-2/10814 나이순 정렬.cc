#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct type {
  int a;
  int b;
  string c;
};

bool cmp(const type &a, const type &b) {
  if (a.b == b.b)
    return a.a < b.a;
  else
    return a.b < b.b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<type> arr;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    type t;
    t.a = i;
    cin >> t.b >> t.c;
    arr.emplace_back(t);
  }
  sort(arr.begin(), arr.end(), cmp);
  for (int i = 0; i < N; i++) cout << arr[i].b << " " << arr[i].c << "\n";
}