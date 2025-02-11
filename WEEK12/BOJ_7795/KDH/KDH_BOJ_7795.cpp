#include <algorithm>
#include <iostream>

using namespace std;

int T, N, M, cnt = 0;
int A[20001], B[20001];

void Input() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) cin >> A[i];
  for (int j = 0; j < M; j++) cin >> B[j];
}

int modified_binary_search(int target) {
  int left = 0, right = M - 1, result = -1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (target > B[mid]) {
      left = mid + 1;
      result = mid;
    } else {
      right = mid - 1;
    }
  }

  return result;
}

void Solve() {
  cin >> T;

  for (int t = 0; t < T; t++) {
    Input();

    cnt = 0;

    sort(B, B + M);

    for (int i = 0; i < N; i++) {
      int index = modified_binary_search(A[i]);

      if (index == -1) continue;

      cnt += (index + 1);
    }

    cout << cnt << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}