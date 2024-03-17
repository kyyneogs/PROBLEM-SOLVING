#include <algorithm>
#include <array>
#include <iostream>

using namespace std;
constexpr size_t MAX_SIZE = 100000;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, t1, t2;
    cin >> N;

    array<pair<int, int>, MAX_SIZE> arr;
    for (int i = 0; i < N; i++) {
        cin >> t1 >> t2;
        arr[i] = make_pair(t1, t2);
    }
    sort(arr.begin(), arr.begin() + N, cmp);
    for (int i = 0; i < N; i++)
        cout << arr[i].first << " " << arr[i].second << "\n";
}