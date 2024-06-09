#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct tt {
  int av;
  int v;
};

struct cmp {
  bool operator()(const tt &a, const tt &b) {
    if (a.av == b.av) return a.v > b.v;
    return a.av > b.av;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int N;
  cin >> N;

  priority_queue<tt, vector<tt>, cmp> que;

  while (N--) {
    int t;
    cin >> t;

    if (t == 0) {
      if (!que.empty()) {
        cout << que.top().v << "\n";
        que.pop();
      } else{
        cout << 0 << "\n";
      }
    } else {
      que.push({abs(t), t});
    }
  }
}