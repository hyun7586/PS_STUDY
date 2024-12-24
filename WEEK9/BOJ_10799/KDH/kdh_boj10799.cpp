#include <bits/stdc++.h>
using namespace std;

void Solve() {
  // vars
  string input;
  stack<char> st;
  int cnt = 0;

  // input
  cin >> input;

  // main logic
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '(') {
      if (input[i + 1] == ')') {
        // Laser
        cnt += st.size();
        i += 1;
      } else {
        st.push(input[i]);
      }
    } else if (input[i] == ')') {
      cnt += 1;
      st.pop();
    }
  }

  // print result
  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}