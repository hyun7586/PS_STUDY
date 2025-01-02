#include <bits/stdc++.h>
using namespace std;

int R, C, max_value = 0;
bool visited[20][20] = {false};
bool used[24] = {false};
int arr[20][20];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void Input() {
  cin >> R >> C;

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      // 편의성을 위해 알파벳을 int로 변환해서 저장
      // A==0, B==1, ...
      char ch;
      cin >> ch;
      arr[i][j] = (int)ch - 'A';
    }
}

// dfs searching: recursion
void dfs(int row, int col, int cnt) {
  // 종료 조건은 없음
  // 새로운 칸 발견해서 cnt값 커질 때 max_value를 한 번씩 갱신함.
  if (max_value < cnt) max_value = cnt;

  visited[row][col] = true;
  used[arr[row][col]] = true;

  for (int i = 0; i < 4; i++) {
    int ti = row + direction[i][0];
    int tj = col + direction[i][1];

    // bound check && used/visited check
    if (ti < 0 || ti >= R || tj < 0 || tj >= C) continue;
    if (used[arr[ti][tj]] == true || visited[ti][tj] == true) continue;

    dfs(ti, tj, cnt + 1);

    // recursion 끝나면 다시 used, visited false 처리
    used[arr[ti][tj]] = false;
    visited[ti][tj] = false;
  }
}

void Solve() {
  Input();
  dfs(0, 0, 1);

  cout << max_value;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}