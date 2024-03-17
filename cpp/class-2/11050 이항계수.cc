#include <iostream>

using namespace std;

int facto(int r1, int r2) {
    int result = 1;
    for (int i = r1; i > r1 - r2; i--)
        result *= i;
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

    if (K > N / 2)
        K = N - K;
    cout << facto(N, K) / facto(K, K);
}