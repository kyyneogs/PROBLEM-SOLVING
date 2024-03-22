#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr[15][15] = {
        0,
    };
    for (int i = 1; i < 15; i++)
        arr[0][i] = arr[0][i - 1] + i;
    for (int i = 1; i < 15; i++)
        for (int j = 1; j < 15; j++)
            arr[j][i] = arr[j - 1][i] + arr[j][i - 1];

    int T;
    cin >> T;
    while (T--) {
        int k, n;
        cin >> k >> n;
        cout << arr[k][n] - arr[k][n - 1] << "\n";
    }
}