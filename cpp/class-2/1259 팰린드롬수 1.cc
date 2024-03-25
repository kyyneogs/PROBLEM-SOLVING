#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1;
    while (1) {
        cin >> s1;
        if (s1 == "0")
            break;
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        if (s1 == s2)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}