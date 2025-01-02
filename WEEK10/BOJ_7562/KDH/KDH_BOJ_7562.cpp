#include <bits/stdc++.h>
using namespace std;

int N, T, cnt = 0;
int initial_row, initial_col, goal_row, goal_col;
int direction[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

void Input() {
  cin >> N;

  cin >> initial_row >> initial_col;
  cin >> goal_row >> goal_col;
}

void modified_bfs() {
  // allocate visited array
  int** visited = new int*[N];
  for (int i = 0; i < N; i++) visited[i] = new int[N];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) visited[i][j] = 0;

  // main logic
  queue<pair<int, int>> q;
  q.push(make_pair(initial_row, initial_col));
  // 처음 시작 위치에서 이동횟수를 1로 초기화함 -> 마지막에 cnt 값 출력할 때 1 빼줘야 함
  // 다른 위치로 이동했다가 다시 시작 위치로 돌아오는 case 방지하기 위함
  visited[initial_row][initial_col] = 1;

  while (!q.empty()) {
    pair<int, int> temp = q.front();
    q.pop();

    for (int i = 0; i < 8; i++) {
      int ti = temp.first + direction[i][0];
      int tj = temp.second + direction[i][1];

      // bound check
      if (ti < 0 || ti >= N || tj < 0 || tj >= N) continue;

      // push to queue
      if (visited[ti][tj] == 0) {
        q.push(make_pair(ti, tj));
        visited[ti][tj] = visited[temp.first][temp.second] + 1;
      }

      // exit conditions
      if (ti == goal_row && tj == goal_col) {
        cnt = visited[ti][tj];
        return;
      }
    }
  }
}

void Solve() {
  Input();

  cnt = 0;
  modified_bfs();

  cout << cnt - 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // T번 실행(test case 수)
  cin >> T;
  for (int i = 0; i < T; i++) Solve();

  return 0;
}