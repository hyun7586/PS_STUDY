#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
int **adjacent;
bool *visited;
queue<int> q;

void bfs(int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    adjacent = new int *[n + 1];
    visited = new bool[n + 1];
    for (int i = 0; i <= n; i++)
        adjacent[i] = new int[n + 1];

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        // undirected graph
        adjacent[a][b] = adjacent[b][a] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }

    cout << cnt;

    return 0;
}

void bfs(int start)
{
    if (visited[start] == false)
    {
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            for (int i = 1; i <= n; i++)
            {
                if (adjacent[x][i] == 1 && visited[i] == false)
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        cnt += 1;
    }
}