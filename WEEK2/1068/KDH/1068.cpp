#include <bits/stdc++.h>
using namespace std;

vector<int> arr_child[51];
// arr_child[i]==j -> the child of i node is j
bool visited[51], visited_for_deletion[51];
int cnt_leafs = 0, delete_num, root_node;

void delete_node(int x, int num);
void dfs(int x);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
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

    delete_node(root_node, delete_num);
    dfs(root_node);

    if (delete_num == root_node)
        cout << 0;
    else
        cout << cnt_leafs;

    return 0;
}

void dfs(int x)
{
    visited[x] = true;

    if (arr_child[x].size() == 0)
    {
        // node x is leaf node && node x is not root node
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

void delete_node(int x, int num)
{
    visited_for_deletion[x] = true;

    for (int i = 0; i < arr_child[x].size(); i++)
    {
        int y = arr_child[x][i];
        if (y == delete_num)
        {
            arr_child[x].erase(arr_child[x].begin() + i);
            i -= 1;
            continue;
        }

        if (visited_for_deletion[y] == false)
            delete_node(y, num);
    }
}
