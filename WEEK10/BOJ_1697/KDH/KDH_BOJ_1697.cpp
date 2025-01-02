#include <bits/stdc++.h>
using namespace std;

#define MAX 200002

int subin, sister, level = 0;
bool visited[MAX];
// 수빈이가 해당 위치에 도달할 때까지 걸린 시간
int notation[MAX];

void bfs(int start) {
  // start는 수빈이의 시작위치
  queue<int> q;
  q.push(start);
  notation[start] = 0;
  visited[start] = true;

  while (true) {
    // x는 현재 고려하고 있는 queue의 수빈이 위치
    int x = q.front();

    // 해당 x에 위치한 수빈이가 현재까지 이동하는 데 걸린 시간간
    int timeTaken = notation[x];

    if (x == sister) {
      // 특정 queue가 동생의 위치에 도달하면 바로 종료
      // 먼저 도달한 queue가 무조건 가장 빠르게 도달한 case임.
      cout << notation[x];
      break;
    }

    q.pop();
    visited[x] = true;

    // x-1로 이동, x+1로 이동, 2*x로 순간이동 3가지 경우의 수를 고려할 거임
    // 각 case에 대해서 bound check와 visited check를 거친 후에 queue에 push함.

    if ((x - 1 >= 0 && x - 1 <= 200000) && !visited[x - 1]) {
      q.push(x - 1);
      notation[x - 1] = timeTaken + 1;
      visited[x - 1] = true;
    }

    if ((x + 1 >= 0 && x + 1 <= 200000) && !visited[x + 1]) {
      q.push(x + 1);
      notation[x + 1] = timeTaken + 1;
      visited[x + 1] = true;
    }

    if ((2 * x >= 0 && 2 * x <= 200000) && !visited[2 * x]) {
      q.push(2 * x);
      notation[2 * x] = timeTaken + 1;
      visited[2 * x] = true;
    }
  }
}

void Solve() {
  cin >> subin >> sister;

  bfs(subin);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}