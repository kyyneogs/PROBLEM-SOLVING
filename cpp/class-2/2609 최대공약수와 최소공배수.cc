#include <iostream>

using namespace std;

int foo(int a, int b) {
    if (a % b == 0)
        return b;
    return foo(b, a % b);
}

int main() {
    int N, M;
    cin >> N >> M;

    int maxi = foo(N, M);
    int mini = maxi * (N / maxi) * (M / maxi);
    cout << maxi << "\n" << mini;
}