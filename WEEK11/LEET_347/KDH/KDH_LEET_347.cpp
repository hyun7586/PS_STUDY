#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; }

class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> m;
    vector<int> result;

    for (auto each : nums) m[each] += 1;

    vector<pair<int, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < k; i++) result.push_back(v[i].first);

    return result;
  }
};