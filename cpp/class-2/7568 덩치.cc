#include <array>
#include <iostream>

using namespace std;

int main() {
    int N;
    array<pair<int, int>, 50> arr;
    int answer[50] = {
        0,
    };
    cin >> N;
    for (int i = 0; i < N; i++)
        answer[i] = 1;

    for (int T = 0; T < N; T++) {
        int x, y;
        cin >> x >> y;
        arr[T] = make_pair(x, y);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            if (arr[i].first > arr[j].first && arr[i].second > arr[j].second)
                answer[j]++;
        }
    }
    for (int i = 0; i < N; i++)
        cout << answer[i] << " ";
}
