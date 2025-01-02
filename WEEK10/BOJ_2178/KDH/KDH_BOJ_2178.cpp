#include <bits/stdc++.h>
using namespace std;

#define MAX 101

int n, m;
int graph[MAX][MAX], dist[MAX][MAX];
bool visited[MAX][MAX];

int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int row, int col) {
  queue<pair<int, int>> q;
  q.push(make_pair(row, col));
  visited[row][col] = true;

  dist[row][col] += 1;

  while (!q.empty()) {
    pair<int, int> temp = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ti = temp.first + direction[i][0];
      int tj = temp.second + direction[i][1];

      if (ti < 1 || ti > n || tj < 1 || tj > m || graph[ti][tj] == 0) continue;

      if (visited[ti][tj] == false && graph[ti][tj] == 1) {
        q.push(make_pair(ti, tj));
        visited[ti][tj] = true;
        dist[ti][tj] = dist[temp.first][temp.second] + 1;
      }
    }
  }
}

void Input() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      dist[i][j] = 0;

      char ch = cin.get();
      if (ch == '\n') ch = cin.get();

      graph[i][j] = ch - '0';
    }
}

void Solve() {
  Input();
  bfs(1, 1);

  cout << dist[n][m];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}
