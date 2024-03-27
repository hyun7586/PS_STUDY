#include <bits/stdc++.h>
using namespace std;

vector<int> tree[500001];
bool visited[500001];
long long cnt = 0;

void dfs(int x, long long level);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1, 0);

    if (cnt % 2 == 1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

void dfs(int x, long long level)
{
    visited[x] = true;

    if (x != 1 && tree[x].size() == 1)
    {
        cnt += level;
        return;
    }

    for (auto each : tree[x])
    {
        if (!visited[each])
        {
            dfs(each, level + 1);
        }
    }
}