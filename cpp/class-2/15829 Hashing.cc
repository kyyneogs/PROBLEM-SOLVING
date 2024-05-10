#include <iostream>
#include <string>

using namespace std;
constexpr int _k = 96;
constexpr int M = 1234567891;
constexpr int r = 31;

inline double _pow(int a, int b) {
  long long k = 1;
  for(int i=0; i < b; i++){
    k *= a;
    k %= M;
  }
  return k;
}

int main() {
  int N;
  cin >> N;

  string s;
  cin >> s;

  long long t = 0;
  for (int i=0; i<s.size(); i++) {
    int k = int(s[i]) - _k;
    t += k * _pow(r, i);
    t %= M;
  }

  int hash = t % M;
  cout << hash;
}