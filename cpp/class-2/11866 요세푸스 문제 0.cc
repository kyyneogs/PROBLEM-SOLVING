#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;

    cin >> N >> K;
    deque<int> que;
    deque<int> ans;

    for (int i = 0; i < N; i++)
        que.push_back(i + 1);

    while (!que.empty()) {
        for (int i = 0; i < K - 1; i++) {
            que.push_back(que.front());
            que.pop_front();
        }
        ans.push_back(que.front());
        que.pop_front();
    }
    cout << "<";
    for (int i = 0; i < N - 1; i++) {
        cout << ans[i] << ", ";
    }
    cout << ans[N - 1] << ">";
}