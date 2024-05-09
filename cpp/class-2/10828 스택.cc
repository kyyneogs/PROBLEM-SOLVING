#include <functional>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

stack<int> stk;

void spush() {
  int t;
  cin >> t;
  stk.push(t);
}

void spop() {
  if (stk.empty())
    cout << "-1" << "\n";
  else {
    cout << stk.top() << "\n";
    stk.pop();
  }
}

void ssize() { cout << stk.size() << "\n"; }

void sempty() { cout << (int)stk.empty() << "\n"; }

void stop() {
  if (stk.empty())
    cout << "-1\n";
  else
    cout << stk.top() << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  map<string, function<void()>> dict = {
    {"push", std::move(bind(spush))},
    {"pop", std::move(bind(spop))},
    {"size", std::move(bind(ssize))},
    {"empty", std::move(bind(sempty))},
    {"top", std::move(bind(stop))}
    };

  int N;
  cin >> N;
  while (N--) {
    string s;
    cin >> s;
    auto it = dict.find(s);
    it->second();
  }
}