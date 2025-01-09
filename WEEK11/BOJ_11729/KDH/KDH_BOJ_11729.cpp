#include <bits/stdc++.h>
using namespace std;

int input, N;
priority_queue<int> pq;

void Solve() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> input;

    if (input == 0) {
      if (pq.empty()) {
        cout << 0 << '\n';
      } else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else {
      pq.push(input);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}