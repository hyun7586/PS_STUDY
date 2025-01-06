#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
  if (a.second == b.second) return a.first < b.first;

  return a.second > b.second;
}

class Solution {
 public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    vector<string> result;

    map<string, int> m;
    for (auto each : words) m[each] += 1;

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < k; i++) result.push_back(v[i].first);

    return result;
  }
};