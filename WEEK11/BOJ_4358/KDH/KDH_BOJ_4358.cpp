#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

void Solve() {
  string input;
  int n = 0;

  while (getline(cin, input, '\n')) {
    if (input == "") continue;

    m[input] += 1;
    n += 1;
  }

  // 소숫점 아래 4째자리 반올림 설정정
  cout << fixed << setprecision(4);
  for (auto each : m) {
    cout << each.first << " " << (double)each.second / n * 100 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}