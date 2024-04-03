#include <iostream>
#include <deque>

using namespace std;

int main() {
  deque<int> que;
  int n;
  cin >> n;

  for(int i=0; i<n; i++) que.push_back(i+1);
  while(que.size() > 1) {
    que.pop_front();
    que.push_back(que.front());
    que.pop_front();
  }
  cout << que[0];
}