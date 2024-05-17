#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  vector<pair<int, int>> sam;
  int N;
  cin >> N;

  int arr[8001] = {0, };

  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    arr[t + 4000]++;
  }

  int begin = 4001, end = -4001, mid = 0, sumi = 0, cnt = 1;

  for (int i = 0; i < 8001; i++) {
    if (!arr[i]) continue;
    int value = i - 4000;
    int count = arr[i];

    if (sam.empty() || sam.back().second == count) {
      sam.push_back(make_pair(value, count));
    } else if (sam.back().second < count) {
      sam.clear();
      sam.push_back(make_pair(value, count));
    }

    sumi += value * count;
    mid = (cnt <= N / 2 + 1) ? value : mid;
    begin = (value < begin) ? value : begin;
    end = (value > end) ? value : end;
    cnt += count;
  }

  cout << (int)round(double(sumi) / double(N)) << "\n";
  cout << mid << "\n";
  int idx = 0;
  if (sam.size() > 1) idx = 1;
  cout << sam[idx].first << "\n";
  cout << end - begin;
}