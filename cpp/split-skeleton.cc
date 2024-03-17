#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string &str, char deli) {
    vector<string> tokens;
    string token;
    unsigned long start = 0, pos = 0;
    while ((pos = str.find(deli, start)) != string::npos) {
        token = str.substr(start, pos - start);
        tokens.push_back(token);
        start = pos + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
};

int main() {
    string s;
    getline(cin, s);
    vector<string> output = split(s, ' ');
    for (auto& i : output)
        cout << i << "\n";
}