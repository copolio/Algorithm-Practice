#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, f;
  vector<int> test, answer;

  cin >> n >> f;
  for (int i = 0; i < n; i++) {
      test.push_back(i+1);
  }

  do {
    int table[n][n];
            for (int i = 0; i < n; i++) {
                table[0][i] = test[i];
            }
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n - i; j++) {
                    table[i][j] = table[i-1][j] + table[i-1][j+1];
                }
            }
            if (table[n-1][0] == f) {
                answer = test;
                break;
            }
  } while(next_permutation(test.begin(), test.end()))

  cout << answer;

  return 0;
}