#include <bits/stdc++.h>
using namespace std;

int N;
string s;

void Input() {
  cin >> N;
  cin >> s;
}

void Solve() {
  Input();

  // stack<index>를 저장장
  stack<int> st;

  // 현재 index에 위치한 문자가 올바른 문자열에 속하는지를 기록하는 배열열
  bool *isCorrectString = new bool[N];
  for (int i = 0; i < N; i++) isCorrectString[i] = false;

  // string s를 한 문자씩 순회함.
  for (int i = 0; i < N; i++) {
    if (s[i] == '(') {
      // '(' 라면 stack에 push함.
      st.push(i);
    } else {
      // ')'라면
      // 동시에 st이 비어있지 않다면 짝에 맞는 '('가 존재한다는 의미
      // 짝에 맞는 괄호 둘 다 올바른 문자열에 포함시킴.
      if (!st.empty()) {
        isCorrectString[i] = true;
        int index = st.top();
        st.pop();
        isCorrectString[index] = true;
      }
    }
  }

  // 올바른 문자열 기록 배열을 순회하면서 가장 길고 연속적으로 나오는 true의 개수를 출력할 거임.
  int cnt = 0, max_value = 0;
  for (int i = 0; i < N; i++) {
    if (isCorrectString[i]) cnt += 1;

    if (isCorrectString[i] == false || i == N - 1) {
      max_value = max(max_value, cnt);
      cnt = 0;
    }
  }

  cout << max_value;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}