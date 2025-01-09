#include <bits/stdc++.h>
using namespace std;

int N;

// median 값 이하 원소들은 max_heap에 저장, max_heap은 원소값이 큰 순서대로 pop됨.
// median 값 이상 원소들은 min_heap에 저장, min_heap은 원소값이 작은 순서대로 pop됨.
priority_queue<int, vector<int>> max_heap;
priority_queue<int, vector<int>, greater<>> min_heap;

void Solve() {
  int input;
  cin >> N;

  // 항상 max_heap.top()이 median 값이라고 생각하면 됨.
  for (int i = 0; i < N; i++) {
    cin >> input;

    // median 값보다 작거나 max_heap이 비어있다면 max_heap에 push
    if (max_heap.empty() || input <= max_heap.top()) max_heap.push(input);

    // median 값보다 크거나, max_heap.size()와 min_heap.size()가 2 이상 벌어졌다면 min_heap에 push
    else if (input > max_heap.top() || max_heap.size() > min_heap.size() - 1)
      min_heap.push(input);

    // max_heap, min_heap의 원소개수가 많이 차이났을 때 조정 과정
    // 두 pq의 개수 차이가 2개 이상 차이나면 많은 쪽에서 적은 쪽으로 원소 이동
    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }

    if (max_heap.size() < min_heap.size()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }

    // 각 과정마다 median 값 출력
    cout << max_heap.top() << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}