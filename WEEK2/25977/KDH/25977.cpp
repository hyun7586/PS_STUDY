#include <bits/stdc++.h>
using namespace std;

// node number start from 0
vector<int> tree[18];
bool visited[18];
int content[18];

int apples = 0, peers = 0, k;

void dfs(int x);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++)
    {
        int p, c;
        cin >> p >> c;
        tree[p].push_back(c);
    }

    for (int i = 0; i < n; i++)
        cin >> content[i];

    return 0;
}

void dfs(int x)
{
    visited[x] = true;
    if (content[x] == 1)
        apples += 1;

    for (auto each : tree[x])
    {
        if (!visited[each])
            dfs(each);
    }
}