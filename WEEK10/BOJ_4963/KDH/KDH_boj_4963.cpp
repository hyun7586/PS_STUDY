#include <bits/stdc++.h>
using namespace std;

int w, h;
int arr[50][50];
int direction[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
bool visited[50][50];

void Input() {
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) cin >> arr[i][j];
}

void bfs(int r, int c) {
  queue<pair<int, int>> q;
  q.push(make_pair(r, c));

  while (!q.empty()) {
    pair<int, int> temp = q.front();
    q.pop();
    visited[temp.first][temp.second] = true;

    for (int i = 0; i < 8; i++) {
      int next_r = temp.first + direction[i][0];
      int next_c = temp.second + direction[i][1];

      if (next_r < 0 || next_r >= h || next_c < 0 || next_c >= w) continue;

      if (!visited[next_r][next_c] && arr[next_r][next_c] == 1) {
        q.push(make_pair(next_r, next_c));
        visited[next_r][next_c] = true;
      }
    }
  }
}

void func() {
  int cnt = 0;

  // clear visited array
  memset(visited, false, sizeof(visited));

  // main logic(bfs)
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!visited[i][j] && arr[i][j] == true) {
        bfs(i, j);
        cnt += 1;
      }
    }
  }

  cout << cnt << '\n';
}

void Solve() {
  cin >> w >> h;

  while (!(w == 0 && h == 0)) {
    Input();
    func();
    cin >> w >> h;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}