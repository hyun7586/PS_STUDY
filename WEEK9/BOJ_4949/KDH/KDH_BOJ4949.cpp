#include <bits/stdc++.h>
using namespace std;

vector<string> v;

void Input() {
  while (1) {
    string temp;

    getline(cin, temp, '\n');

    if (temp == ".") break;

    v.push_back(temp);
  }
}

void Solve() {
  for (string each : v) {
    stack<char> st;
    for (char ch : each) {
      if (ch == '.') {
        // exit conditions
        if (st.size() == 0) {
          cout << "yes\n";
        } else {
          cout << "no\n";
        }
      } else if (ch == '(' || ch == '[') {
        st.push(ch);
      } else if (ch == ')') {
        if (st.size() != 0 && st.top() == '(') {
          st.pop();
        } else {
          cout << "no\n";
          break;
        }
      } else if (ch == ']') {
        if (st.size() != 0 && st.top() == '[') {
          st.pop();
        } else {
          cout << "no\n";
          break;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Input();
  Solve();

  return 0;
}