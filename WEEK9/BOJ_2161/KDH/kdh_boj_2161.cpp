#include <bits/stdc++.h>
using namespace std;

int N;

void Solve() {
  cin >> N;

  queue<int> q;

  for (int i = 1; i <= N; i++) q.push(i);

  while (q.size() > 1) {
    cout << q.front() << " ";
    q.pop();

    q.push(q.front());
    q.pop();
  }

  cout << q.front();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}