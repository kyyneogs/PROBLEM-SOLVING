#include <array>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int N, M, mini = 50 * 50;
  array<string, 8> ans;
  array<string, 50> input;

  for (int i = 0; i < 8; i++) {
    if (i % 2 == 0)
      ans[i] = "WBWBWBWB";
    else
      ans[i] = "BWBWBWBW";
  }

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> input[i];

  for (int dx = 0; dx <= N - 8; dx++) {
    for (int dy = 0; dy <= M - 8; dy++) {
      int w2b = 0, b2w = 0, tmini = 50 * 50;

      for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
          if (input[x + dx][y + dy] != ans[x][y])
            b2w++;
          else
            w2b++;
        }
      }
      tmini = (w2b > b2w) ? b2w : w2b;
      mini = (tmini > mini) ? mini : tmini;
    }
  }
  cout << mini;
}