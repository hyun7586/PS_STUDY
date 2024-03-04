/*
단방향/양방향 그래프 주의
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, start;
bool visited[1001];
vector<int> graph[1001];

void dfs(int x);
void bfs(int x);
void visited_clear();

int main()
{
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++)
    {
        int temp_x, temp_y;
        cin >> temp_x >> temp_y;

        graph[temp_x].push_back(temp_y);
        graph[temp_y].push_back(temp_x);
    }

    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(start);
    memset(visited, 0, n + 1);
    cout << '\n';
    bfs(start);

    return 0;
}

void dfs(int x)
{
    visited[x] = true;
    cout << x << " ";

    for (int i = 0; i < graph[x].size(); i++)
    {
        int y = graph[x][i];
        if (!visited[y])
            dfs(y);
    }
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while (!q.empty())
    {
        int y = q.front();
        q.pop();
        cout << y << " ";

        for (int i = 0; i < graph[y].size(); i++)
        {
            int k = graph[y][i];
            if (!visited[k])
            {
                q.push(k);
                visited[k] = true;
            }
        }
    }
}
