#include <bits/stdc++.h>
using namespace std;

vector<int> arr_child[51];
bool visited[51];
int cnt_leafs = 0, delete_num;

void dfs(int x);
void dfs_delete(int x);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, root_node;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int parent;
        cin >> parent;

        if (parent == -1)
            root_node = i;
        else
            arr_child[parent].push_back(i);
    }

    cin >> delete_num;

    dfs(root_node);
    cout << cnt_leafs;

    return 0;
}

void dfs(int x)
{
    visited[x] = true;

    if (arr_child[x].size() == 0)
    {
        // node x is leaf node
        cnt_leafs += 1;
        return;
    }
    else
    {
        for (auto each : arr_child[x])
        {
            if (visited[each] == false)
                dfs(each);
        }
    }
}

void dfs_delete(int x)
{
    visited[x] = true;

    // root가 delete되는ㄴ 경우 고려해야 함.

    if (arr_child[x].size() != 0)
    {
        for (auto each : arr_child[x])
        {
            if (!visited[each])
                dfs(each);

            if (each == delete_num)
            {
                // delete each from arr_child[x]
            }
        }
    }
}