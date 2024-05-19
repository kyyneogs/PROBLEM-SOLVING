#include <iostream>
#pragma GCC optimize("Ofast")
#define mg 1000000
#define sz 2000001

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> n;

  int arr[sz] = {0, };
  for(int i=0; i<n; i++) {
    int t;
    cin >> t;
    arr[t+mg] = 1;
  }

  for(int i=0; i<sz; i++) {
    if (arr[i] == 0) continue;
    cout << i - mg << "\n";
  }
}