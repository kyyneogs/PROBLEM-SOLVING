#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long result = 0;
    deque<int> que;
    int k = 0, t;
    cin >> k;
    while (k--) {
        cin >> t;
        if (t == 0) {
            que.pop_back();
            continue;
        }
        que.push_back(t);
    }
    for (int i = 0; i < que.size(); i++)
        result += que[i];
    cout << result;
}