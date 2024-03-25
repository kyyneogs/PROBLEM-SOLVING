#include <iostream>

using namespace std;

int main() {
    while (1) {
        int s1;
        cin >> s1;
        if (s1 == 0)
            break;
        int t = s1 / 10, s2 = s1 % 10;
        while (t > 0) {
            s2 = 10 * s2 + t % 10;
            t /= 10;
        }
        if (s1 == s2)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}