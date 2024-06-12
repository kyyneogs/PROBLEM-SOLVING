#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int N;
  cin >> N;

  priority_queue<int> que;
  while(N--) {
    int t;
    cin >> t;
    if (t == 0){
      if (que.empty()) cout << "0\n";
      else {
        cout << que.top() << "\n";
        que.pop();
      }
      continue;
    }
    que.push(t);
  }
}