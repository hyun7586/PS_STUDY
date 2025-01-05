#include <bits/stdc++.h>
using namespace std;

int N, M, start, goal;
int MAP[1001][1001];
int dist[1001];
bool visited[1001];

void Input() {
  cin >> N >> M;

  // initialize MAP
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      if (i == j)
        MAP[i][j] = 0;
      else
        MAP[i][j] = INT_MAX;
    }

  // input: MAP
  for (int i = 0; i < M; i++) {
    int a, b, value;
    cin >> a >> b >> value;

    if (MAP[a][b] < value) continue;

    MAP[a][b] = value;
  }

  cin >> start >> goal;

  // initialize dist
  for (int i = 1; i <= N; i++) dist[i] = MAP[start][i];
}

void Solve() {
  Input();

  // pair<value, index>
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  // initialize priority queue: push dist array
  for (int i = 1; i <= N; i++) {
    if (i == start || dist[i] == INT_MAX) continue;

    pq.push(make_pair(dist[i], i));
  }

  // main logic : traversal dist, pop from pq, relaxation dist
  while (!pq.empty()) {
    // pop from pq
    // valud: temp.first
    // index: temp.second

    pair<int, int> temp = pq.top();
    pq.pop();

    // relaxation dist
    // i: end_point, calculate the cost of (start -> end_point)
    for (int i = 1; i <= N; i++) {
      if (MAP[temp.second][i] == INT_MAX) continue;

      if (dist[i] > dist[temp.second] + MAP[temp.second][i]) {
        dist[i] = dist[temp.second] + MAP[temp.second][i];
        pq.push(make_pair(dist[i], i));
      }
    }
  }

  // print start -> goal cost
  cout << dist[goal];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}