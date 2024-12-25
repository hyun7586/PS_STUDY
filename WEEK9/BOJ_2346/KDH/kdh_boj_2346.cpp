#include <bits/stdc++.h>
using namespace std;

int N;
// deque<pair<index, value>
// index는 1부터 시작한다.
deque<pair<int, int>> dq;

void Input() {
  int temp;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> temp;
    dq.push_back(make_pair(i, temp));
  }
}

void Solve() {
  Input();

  // deque가 빌 때까지 반복한다.
  while (dq.size() != 0) {
    // 항상 deque.front() 자리에 있는 원소를 출력할 거임.(풍선을 터트리는 위치는 항상 deque.front())
    auto it = dq.front();
    dq.pop_front();
    cout << it.first << " ";

    // it.second는 0이 아님
    // it.second 값만큼 deque자체를 오른쪽/왼쪽으로 회전시키는 과정임.

    // it.second 값이 양수라면 오른쪽으로 회전: deque의 front 원소를 back으로 옮김.
    // 위에서 deque.front()를 이미 pop했기 때문에 오른쪽으로 1회 회전된 상태임.
    // -> it.second-1번만큼만 더 회전하면 됨.
    if (it.second > 0) {
      for (int i = 0; i < it.second - 1; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    }

    // it.second 값이 음수라면 왼쪽으로 회전: deque의 back 원소를 front로 옮김.
    // it.second번 왼쪽으로 회전.
    else {
      for (int i = 0; i < (-1) * it.second; i++) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
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