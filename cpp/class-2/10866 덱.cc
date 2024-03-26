#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    deque<int> que;
    int N, t;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;
        if (s == "push_front") {
            cin >> t;
            que.push_front(t);
        } else if (s == "push_back") {
            cin >> t;
            que.push_back(t);
        } else if (s == "pop_front") {
            if (que.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << que.front() << "\n";
            que.pop_front();
        } else if (s == "pop_back") {
            if (que.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << que.back() << "\n";
            que.pop_back();
        } else if (s == "size") {
            cout << que.size() << "\n";
        } else if (s == "empty") {
            cout << (int)que.empty() << "\n";
        } else if (s == "front") {
            if (que.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << que.front() << "\n";
        } else if (s == "back") {
            if (que.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << que.back() << "\n";
        }
    }
}